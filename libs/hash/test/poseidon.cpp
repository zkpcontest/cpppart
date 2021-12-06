//---------------------------------------------------------------------------//
// Copyright (c) 2020 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020 Ilias Khairullin <ilias@nil.foundation>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//---------------------------------------------------------------------------//

#define BOOST_TEST_MODULE poseidon_test

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

// #include <nil/crypto3/hash/algorithm/hash.hpp>
// #include <nil/crypto3/hash/adaptor/hashed.hpp>

#include <nil/crypto3/hash/poseidon.hpp>
#include <nil/crypto3/algebra/fields/bls12/scalar_field.hpp>

using namespace nil::crypto3;
using namespace nil::crypto3::algebra;
// using namespace nil::crypto3::accumulators;

using poseidon_default_field_t = fields::bls12_fr<381>;

template<typename FieldParams>
void print_field_element(std::ostream &os, const typename fields::detail::element_fp<FieldParams> &e) {
    os << e.data << std::endl;
}

namespace boost {
    namespace test_tools {
        namespace tt_detail {
            template<typename FieldParams>
            struct print_log_value<typename fields::detail::element_fp<FieldParams>> {
                void operator()(std::ostream &os, typename fields::detail::element_fp<FieldParams> const &e) {
                    print_field_element(os, e);
                }
            };

            template<template<typename, typename> class P, typename K, typename V>
            struct print_log_value<P<K, V>> {
                void operator()(std::ostream &, P<K, V> const &) {
                }
            };
        }    // namespace tt_detail
    }        // namespace test_tools
}    // namespace boost

// if target == check-hash just data/curves.json
const char *test_data = "../../../../libs/hash/test/data/poseidon.json";

boost::property_tree::ptree string_data(const std::string &interface_type, const std::string &strength,
                                        const std::string &arity) {
    boost::property_tree::ptree string_data;
    boost::property_tree::read_json(test_data, string_data);

    return string_data.get_child(interface_type).get_child(strength).get_child(arity);
}

template<typename poseidon_functions_t, typename TestSet>
void hash_test_data(const TestSet &test_set) {
    using element_type = typename poseidon_functions_t::element_type;
    using modulus_type = typename poseidon_functions_t::element_type::modulus_type;

    typename poseidon_functions_t::state_type input;
    typename poseidon_functions_t::state_type input_optimized;

    auto i = 0;
    for (auto &input_value : test_set.second) {
        input[i] = element_type(modulus_type(input_value.second.data()));
        input_optimized[i] = input[i];
        i++;
    }

    auto result_hash = element_type(modulus_type(test_set.first.data()));

    poseidon_functions_t::permute(input);
    poseidon_functions_t::permute_optimized(input_optimized);

    BOOST_CHECK_EQUAL(input[1], result_hash);
    BOOST_CHECK_EQUAL(input_optimized[1], result_hash);
}

BOOST_AUTO_TEST_SUITE(poseidon_manual_tests)

BOOST_DATA_TEST_CASE(poseidon_strengthen_1, string_data("internal", "strengthen", "1"), data_set) {
    using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 1, 69>;

    hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_strengthen_2, string_data("internal", "strengthen", "2"), data_set) {
    using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 2, 69>;

    hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_strengthen_4, string_data("internal", "strengthen", "4"), data_set) {
    using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 4, 70>;

    hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_strengthen_8, string_data("internal", "strengthen", "8"), data_set) {
    using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 8, 72>;

    hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_strengthen_11, string_data("internal", "strengthen", "11"), data_set) {
   using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 11, 72>;

   hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_strengthen_16, string_data("internal", "strengthen", "16"), data_set) {
   using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 16, 74>;

   hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_strengthen_24, string_data("internal", "strengthen", "24"), data_set) {
   using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 24, 74>;

   hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_strengthen_36, string_data("internal", "strengthen", "36"), data_set) {
   using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 36, 75>;

   hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_standart_1, string_data("internal", "standart", "1"), data_set) {
    using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 1, 55>;

    hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_standart_2, string_data("internal", "standart", "2"), data_set) {
    using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 2, 55>;

    hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_standart_4, string_data("internal", "standart", "4"), data_set) {
    using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 4, 56>;

    hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_standart_8, string_data("internal", "standart", "8"), data_set) {
    using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 8, 57>;

    hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_standart_11, string_data("internal", "standart", "11"), data_set) {
   using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 11, 57>;

   hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_standart_16, string_data("internal", "standart", "16"), data_set) {
   using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 16, 59>;

   hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_standart_24, string_data("internal", "standart", "24"), data_set) {
   using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 24, 59>;

   hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_DATA_TEST_CASE(poseidon_standart_36, string_data("internal", "standart", "36"), data_set) {
   using poseidon_functions_t = hashes::detail::poseidon_functions<poseidon_default_field_t, 36, 60>;

   hash_test_data<poseidon_functions_t>(data_set);
}

BOOST_AUTO_TEST_SUITE_END()
