//---------------------------------------------------------------------------//
// Copyright (c) 2018-2021 Mikhail Komarov <nemo@nil.foundation>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//---------------------------------------------------------------------------//

#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

#include "detail/r1cs_examples.hpp"
#include "detail/sha256_component.hpp"

#include <nil/crypto3/algebra/curves/bls12.hpp>
#include <nil/crypto3/algebra/fields/bls12/base_field.hpp>
#include <nil/crypto3/algebra/fields/bls12/scalar_field.hpp>
#include <nil/crypto3/algebra/fields/arithmetic_params/bls12.hpp>
#include <nil/crypto3/algebra/curves/params/multiexp/bls12.hpp>
#include <nil/crypto3/algebra/curves/params/wnaf/bls12.hpp>
#include <nil/crypto3/algebra/pairing/bls12.hpp>
#include <nil/crypto3/algebra/pairing/mnt4.hpp>
#include <nil/crypto3/algebra/pairing/mnt6.hpp>

#include <nil/crypto3/zk/components/blueprint.hpp>
#include <nil/crypto3/zk/components/blueprint_variable.hpp>
#include <nil/crypto3/zk/components/disjunction.hpp>

#include <nil/crypto3/zk/snark/schemes/ppzksnark/r1cs_gg_ppzksnark.hpp>
#include <nil/crypto3/zk/snark/schemes/ppzksnark/r1cs_gg_ppzksnark/marshalling.hpp>

#include <nil/crypto3/zk/snark/algorithms/generate.hpp>
#include <nil/crypto3/zk/snark/algorithms/verify.hpp>
#include <nil/crypto3/zk/snark/algorithms/prove.hpp>
#include <nil/crypto3/algebra/curves/bls12.hpp>
#include <nil/crypto3/algebra/fields/bls12/base_field.hpp>
#include <nil/crypto3/algebra/fields/bls12/scalar_field.hpp>
#include <nil/crypto3/algebra/fields/arithmetic_params/bls12.hpp>
#include <nil/crypto3/algebra/curves/params/multiexp/bls12.hpp>
#include <nil/crypto3/algebra/curves/params/wnaf/bls12.hpp>

#include <nil/crypto3/zk/components/blueprint.hpp>
#include <nil/crypto3/zk/components/blueprint_variable.hpp>
#include <nil/crypto3/zk/components/comparison.hpp>
#include <nil/crypto3/zk/components/hashes/knapsack/knapsack_component.hpp>

#include <nil/crypto3/zk/snark/schemes/ppzksnark/r1cs_gg_ppzksnark.hpp>
#include <nil/crypto3/zk/snark/schemes/ppzksnark/r1cs_gg_ppzksnark/marshalling.hpp>
//#include <nil/crypto3/zk/components/basic_components.hpp>

#include <nil/crypto3/zk/snark/relations/constraint_satisfaction_problems/r1cs.hpp>
using namespace nil::crypto3::zk;
using namespace nil::crypto3::algebra;
#include <nil/marshalling/status_type.hpp>
#include <nil/crypto3/marshalling/types/zk/r1cs_gg_ppzksnark/primary_input.hpp>
#include <nil/crypto3/marshalling/types/zk/r1cs_gg_ppzksnark/proof.hpp>
#include <nil/crypto3/marshalling/types/zk/r1cs_gg_ppzksnark/verification_key.hpp>
#include "main.hpp"
using namespace nil::crypto3;
using namespace nil::crypto3::marshalling;
using namespace nil::crypto3::zk;
using namespace nil::crypto3::zk::components;
using Endianness = nil::marshalling::option::big_endian;
using unit_type = unsigned char;
typedef algebra::curves::bls12<381> curve_type;
typedef typename curve_type::scalar_field_type field_type;
using Endianness = nil::marshalling::option::big_endian;
using unit_type = unsigned char;
using namespace std;
// using scheme_type = SchemeType;

boost::filesystem::path PROVING_KEY_PATH = "p_key";
boost::filesystem::path VERIFICATION_KEY_PATH = "v_key";
boost::filesystem::path PROOF_PATH = "proof";
boost::filesystem::path INPUT_PATH = "pi";
boost::filesystem::path viout = "viout";

std::vector<std::uint8_t> readfile(boost::filesystem::path path) {
    boost::filesystem::ifstream stream(path, std::ios::in | std::ios::binary);
    auto eos = std::istreambuf_iterator<char>();
    auto buffer = std::vector<uint8_t>(std::istreambuf_iterator<char>(stream), eos);
    return buffer;
}

typedef zk::snark::r1cs_gg_ppzksnark<curve_type> scheme_type;

// using namespace nil::crypto3::zk::components;
// using namespace nil::marshalling;

template<typename FieldType>
components::blueprint<FieldType> test_disjunction_component(size_t w) {
    
    using field_type = FieldType;

    std::size_t n = std::log2(w) + 
        ((w > (1ul << std::size_t(std::log2(w))))? 1 : 0);

    components::blueprint<field_type> bp;
    components::blueprint_variable<field_type> output;
    output.allocate(bp);

    bp.set_input_sizes(1);

    components::blueprint_variable_vector<field_type> inputs;
    inputs.allocate(bp, n);

    components::disjunction<field_type> d(bp, inputs, output);
    d.generate_r1cs_constraints();

    for (std::size_t j = 0; j < n; ++j) {
        bp.val(inputs[j]) = typename field_type::value_type((w & (1ul << j)) ? 1 : 0);
    }

    d.generate_r1cs_witness();

    assert(bp.val(output) == (w ? field_type::value_type::one() : field_type::value_type::zero()));
    assert(bp.is_satisfied());

    return bp;
}

long long f(int ballot_num) {return ballot_num * ballot_num * ballot_num + ballot_num;}

// bool trusted_setup() {
//     int ballot_number = 1;
//     using field_type = typename curve_type::scalar_field_type;
        
//     // Create blueprint

//     components::blueprint<field_type> bp;
//     components::blueprint_variable<field_type> out;
//     components::blueprint_variable<field_type> x;

//     // Allocate variables

//     out.allocate(bp);
//     x.allocate(bp);

//     // This sets up the blueprint variables
//     // so that the first one (out) represents the public
//     // input and the rest is private input

//     bp.set_input_sizes(1);

//     // Initialize component

//     test_component<field_type> g(bp, out, x);
//     g.generate_r1cs_constraints();
    
//     // Add witness values

//     bp.val(out) = f(ballot_number);
//     bp.val(x) = ballot_number;

//     g.generate_r1cs_witness();
//     // int o = bp.val(out);
//     // std::cout << o << std::endl;
//     assert(bp.is_satisfied());

//     const snark::r1cs_constraint_system<field_type> constraint_system = bp.get_constraint_system();

//     scheme_type::keypair_type keypair = generate<scheme_type>(constraint_system);

//     std::vector<std::uint8_t> proving_key_byteblob =
//         nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process(keypair.first);

//     using verification_key_marshalling_type = nil::crypto3::marshalling::types::r1cs_gg_ppzksnark_verification_key<
//         nil::marshalling::field_type<
//             Endianness>,
//         typename snark::r1cs_gg_ppzksnark<curve_type>::verification_key_type>;

//     verification_key_marshalling_type filled_verification_key_val =
//         nil::crypto3::marshalling::types::fill_r1cs_gg_ppzksnark_verification_key<
//             typename snark::r1cs_gg_ppzksnark<curve_type>::verification_key_type,
//             Endianness>(keypair.second);


//     std::vector<unit_type> verification_key_byteblob;
//     verification_key_byteblob.resize(filled_verification_key_val.length(), 0x00);
//     auto verification_key_write_iter = verification_key_byteblob.begin();

//     typename nil::marshalling::status_type status =
//         filled_verification_key_val.write(verification_key_write_iter,
//             verification_key_byteblob.size());

//     boost::filesystem::ofstream pk_out(PROVING_KEY_PATH);
//     for (const auto &v : proving_key_byteblob) {
//         pk_out << v;
//     }
//     pk_out.close();
//     std::cout << "Proving key is saved to " << PROVING_KEY_PATH << std::endl;

//     boost::filesystem::ofstream vk_out(VERIFICATION_KEY_PATH );
//     for (const auto &v : verification_key_byteblob) {
//         vk_out << v;
//     }
//     vk_out.close();
//     std::cout << "Verification key is saved to " << VERIFICATION_KEY_PATH << std::endl;

//     return true;
// }




int proof_generation(int ballot_number, bool generate_key) {
    using field_type = typename curve_type::scalar_field_type;
        
    // Create blueprint

    components::blueprint<field_type> bp;
    components::blueprint_variable<field_type> out;
    components::blueprint_variable<field_type> x;
    // components::blueprint_variable<field_type> output(bp, 256);

    // Allocate variables

    // output.allocate(bp);
    x.allocate(bp);
    out.allocate(bp);

    // This sets up the blueprint variables
    // so that the first one (out) represents the public
    // input and the rest is private input

    bp.set_input_sizes(1);

    // Initialize component

    test_component<field_type> g(bp, out, x);
    g.generate_r1cs_constraints();
    
    // Add witness values

    bp.val(out) = f(ballot_number);
    bp.val(x) = ballot_number;

    g.generate_r1cs_witness();
    // int o = bp.val(out);
    // std::cout << o << std::endl;
    assert(bp.is_satisfied());



    const snark::r1cs_constraint_system<field_type> constraint_system = bp.get_constraint_system();
    if (generate_key) {
    scheme_type::keypair_type keypair = generate<scheme_type>(constraint_system);
        // typename scheme_type::proving_key_type proving_key = keypair.first;
        // typename scheme_type::verification_key_type verification_key = keypair.second;
        std::vector<std::uint8_t> proving_key_byteblob =
            nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process(keypair.first);


        std::vector<std::uint8_t> verification_key_byteblob =
            nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process(keypair.second);

        boost::filesystem::ofstream pk_out(PROVING_KEY_PATH);
        for (const auto &v : proving_key_byteblob) {
            pk_out << v;
        }
        pk_out.close();
        std::cout << "Proving key is saved to " << PROVING_KEY_PATH << std::endl;

        boost::filesystem::ofstream vk_out(VERIFICATION_KEY_PATH );
        for (const auto &v : verification_key_byteblob) {
            vk_out << v;
        }
        vk_out.close();
        std::cout << "Verification key is saved to " << VERIFICATION_KEY_PATH << std::endl;
    }
    // if (generate_key) {
    //     scheme_type::keypair_type keypair = generate<scheme_type>(constraint_system);
    //     typename scheme_type::proving_key_type proving_key = keypair.first;
    //     typename scheme_type::verification_key_type verification_key = keypair.second;
    //     std::vector<std::uint8_t> proving_key_byteblob =
    //         nil::marshalling::verifier_input_serializer_tvm<scheme_type>::process(keypair.first);

    //     using verification_key_marshalling_type = nil::crypto3::marshalling::types::r1cs_gg_ppzksnark_verification_key<
    //         nil::marshalling::field_type<
    //             Endianness>,
    //         typename snark::r1cs_gg_ppzksnark<curve_type>::verification_key_type>;

    //     verification_key_marshalling_type filled_verification_key_val =
    //         nil::crypto3::marshalling::types::fill_r1cs_gg_ppzksnark_verification_key<
    //             typename snark::r1cs_gg_ppzksnark<curve_type>::verification_key_type,
    //             Endianness>(keypair.second);


    //     std::vector<unit_type> verification_key_byteblob;
    //     verification_key_byteblob.resize(filled_verification_key_val.length(), 0x00);
    //     auto verification_key_write_iter = verification_key_byteblob.begin();

    //     typename nil::marshalling::status_type status =
    //         filled_verification_key_val.write(verification_key_write_iter,
    //             verification_key_byteblob.size());

    //     boost::filesystem::ofstream pk_out(PROVING_KEY_PATH);
    //     for (const auto &v : proving_key_byteblob) {
    //         pk_out << v;
    //     }
    //     pk_out.close();
    //     std::cout << "Proving key is saved to " << PROVING_KEY_PATH << std::endl;

    //     boost::filesystem::ofstream vk_out(VERIFICATION_KEY_PATH );
    //     for (const auto &v : verification_key_byteblob) {
    //         vk_out << v;
    //     }
    //     vk_out.close();
    //     std::cout << "Verification key is saved to " << VERIFICATION_KEY_PATH << std::endl;
        

    // }
    // else {
            std::vector<std::uint8_t> proving_key_byteblob1 = readfile(PROVING_KEY_PATH);
    nil::marshalling::status_type provingProcessingStatus = nil::marshalling::status_type::success;
    typename scheme_type::proving_key_type proving_key = nil::marshalling::verifier_input_deserializer_tvm<scheme_type>::proving_key_process(
        proving_key_byteblob1.cbegin(),
        proving_key_byteblob1.cend(),
        provingProcessingStatus);

    std::vector<std::uint8_t> ver_key_byteblob1 = readfile(VERIFICATION_KEY_PATH);
    nil::marshalling::status_type verProcessingStatus = nil::marshalling::status_type::success;
    typename scheme_type::verification_key_type verification_key = nil::marshalling::verifier_input_deserializer_tvm<scheme_type>::verification_key_process(
        ver_key_byteblob1.cbegin(),
        ver_key_byteblob1.cend(),
        verProcessingStatus);
    // }
    // else {

    const typename snark::r1cs_gg_ppzksnark<curve_type>::proof_type proof = snark::prove<snark::r1cs_gg_ppzksnark<curve_type>>(proving_key, bp.primary_input(), bp.auxiliary_input());

    bool verified = snark::verify<snark::r1cs_gg_ppzksnark<curve_type>>(verification_key, bp.primary_input(), proof);

    std::cout << "Number of R1CS constraints: " << constraint_system.num_constraints() << std::endl;
    std::cout << "Verification status: " << verified << std::endl << std::endl;
    std::cout << "Public:" << std::endl << "Ballot_open: " << f(ballot_number) << std::endl;

        using verification_key_marshalling_type = nil::crypto3::marshalling::types::r1cs_gg_ppzksnark_verification_key<
            nil::marshalling::field_type<
                Endianness>,
            typename snark::r1cs_gg_ppzksnark<curve_type>::verification_key_type>;

    verification_key_marshalling_type filled_verification_key_val =
            nil::crypto3::marshalling::types::fill_r1cs_gg_ppzksnark_verification_key<
                typename snark::r1cs_gg_ppzksnark<curve_type>::verification_key_type,
                Endianness>(verification_key);

    using proof_marshalling_type = nil::crypto3::marshalling::types::r1cs_gg_ppzksnark_proof<
        nil::marshalling::field_type<
            Endianness>,
        typename scheme_type::proof_type>;

    proof_marshalling_type filled_proof_val = 
        nil::crypto3::marshalling::types::fill_r1cs_gg_ppzksnark_proof<
            typename scheme_type::proof_type,
            Endianness>(proof);

    using primary_input_marshalling_type = nil::crypto3::marshalling::types::r1cs_gg_ppzksnark_primary_input<
        nil::marshalling::field_type<
            Endianness>,
        typename scheme_type::primary_input_type>;

    primary_input_marshalling_type filled_primary_input_val = 
        nil::crypto3::marshalling::types::fill_r1cs_gg_ppzksnark_primary_input<
            typename scheme_type::primary_input_type,
            Endianness>(bp.primary_input());

    std::cout << "Marshalling types filled." << std::endl;

    using unit_type = unsigned char;

    std::vector<unit_type> verification_key_byteblob2;
    verification_key_byteblob2.resize(filled_verification_key_val.length(), 0x00);
    auto write_iter = verification_key_byteblob2.begin();

    typename nil::marshalling::status_type status =  
        filled_verification_key_val.write(write_iter, 
            verification_key_byteblob2.size());

    std::vector<unit_type> proof_byteblob;
    proof_byteblob.resize(filled_proof_val.length(), 0x00);
    write_iter = proof_byteblob.begin();

    status = filled_proof_val.write(write_iter, 
            proof_byteblob.size());

    std::vector<unit_type> primary_input_byteblob;

    primary_input_byteblob.resize(filled_primary_input_val.length(), 0x00);
    auto primary_input_write_iter = primary_input_byteblob.begin();

    status = filled_primary_input_val.write(primary_input_write_iter, 
            primary_input_byteblob.size());

    std::cout << "Byteblobs filled." << std::endl;
    boost::filesystem::path VERIFICATION_KEY_PATH1 = "v_key";
    boost::filesystem::path PROVING_KEY_PATH1 = "p_key";
    boost::filesystem::path VIOUT = "viout";
    boost::filesystem::ofstream outv(VERIFICATION_KEY_PATH1);
    for (const auto &vv : verification_key_byteblob2) {
        outv << vv;
    }
    outv.close();

    boost::filesystem::ofstream out1(PROOF_PATH);
    for (const auto &v1 : proof_byteblob) {
        out1 << v1;
    }
    out1.close();

    boost::filesystem::ofstream out2(INPUT_PATH);
    for (const auto &v2 : primary_input_byteblob) {
        out2 << v2;
    }
    out2.close();

    std::vector<std::uint8_t> verifier_input_output_byteblob(proof_byteblob.begin(), proof_byteblob.end());

    verifier_input_output_byteblob.insert(verifier_input_output_byteblob.end(), primary_input_byteblob.begin(),
                                            primary_input_byteblob.end());
    verifier_input_output_byteblob.insert(verifier_input_output_byteblob.end(), verification_key_byteblob2.begin(),
                                            verification_key_byteblob2.end());

    boost::filesystem::ofstream poutf(VIOUT);
    for (const auto &v3 : verifier_input_output_byteblob) {
        poutf << v3;
    }
    poutf.close();

    boost::filesystem::ofstream pk_out(PROVING_KEY_PATH);
    for (const auto &v : proving_key_byteblob1) {
        pk_out << v;
    }
    pk_out.close();
    std::cout << "Proving key is saved to " << PROVING_KEY_PATH << std::endl;





    // using proof_marshalling_type = nil::crypto3::marshalling::types::r1cs_gg_ppzksnark_proof<
    //     nil::marshalling::field_type<
    //         Endianness>,
    //     typename scheme_type::proof_type>;

    // proof_marshalling_type filled_proof_val =
    //     nil::crypto3::marshalling::types::fill_r1cs_gg_ppzksnark_proof<
    //         typename scheme_type::proof_type,
    //         Endianness>(proof);

    // using primary_input_marshalling_type = nil::crypto3::marshalling::types::r1cs_gg_ppzksnark_primary_input<
    //     nil::marshalling::field_type<
    //         Endianness>,
    //     typename scheme_type::primary_input_type>;

    // primary_input_marshalling_type filled_primary_input_val =
    //     nil::crypto3::marshalling::types::fill_r1cs_gg_ppzksnark_primary_input<
    //         typename scheme_type::primary_input_type,
    //         Endianness>(bp.primary_input());

    // /* std::cout << "Marshalling types filled." << std::endl; */

    // std::vector<unit_type> proof_byteblob;
    // proof_byteblob.resize(filled_proof_val.length(), 0x00);
    // auto proof_write_iter = proof_byteblob.begin();

    // typename nil::marshalling::status_type status1;
    // status1 = filled_proof_val.write(proof_write_iter,
    //         proof_byteblob.size());

    // std::vector<unit_type> primary_input_byteblob;

    // primary_input_byteblob.resize(filled_primary_input_val.length(), 0x00);
    // auto primary_input_write_iter = primary_input_byteblob.begin();

    // status1 = filled_primary_input_val.write(primary_input_write_iter,
    //         primary_input_byteblob.size());

    // /* std::cout << "Byteblobs filled." << std::endl; */

    // boost::filesystem::ofstream proof_out(PROOF_PATH);
    // for (const auto &v : proof_byteblob) {
    //     proof_out << v;
    // }
    // proof_out.close();
    // std::cout << "Proof is saved to " << PROOF_PATH << std::endl;

    // boost::filesystem::ofstream primary_input_out(INPUT_PATH);
    // for (const auto &v : primary_input_byteblob) {
    //     primary_input_out << v;
    // }
    // primary_input_out.close();
    // std::cout << "Primary input is saved to " << INPUT_PATH << std::endl;

    // // }
    

    
    return 0;
}

int main(int argc, char *argv[]) {
    int ballot_number;
    boost::program_options::options_description options(
        "R1CS Generic Group PreProcessing Zero-Knowledge Succinct Non-interactive ARgument of Knowledge "
        "(https://eprint.iacr.org/2016/260.pdf) CLI Proof Generator");
    options.add_options()
    ("help", "Display help message")
    ("setup", "Trusted setup phase: key generation")
    ("proof", "Proof generation")
    ("ballot_number", boost::program_options::value<int>(&ballot_number)->default_value(
        123
    ));

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::command_line_parser(argc, argv).options(options).run(), vm);
    boost::program_options::notify(vm);

    if (vm.count("help") || argc < 2) {
        std::cout << options << std::endl;
        return 0;
    } else if (vm.count("setup")) {
        //return 0;
       proof_generation(ballot_number, true);
    } else if (vm.count("proof")) {
        proof_generation(ballot_number, false);
    }
    return 0;
}
