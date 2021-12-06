//---------------------------------------------------------------------------//
// Copyright (c) 2020-2021 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020-2021 Nikita Kaskov <nbering@nil.foundation>
// Copyright (c) 2020-2021 Ilias Khairullin <ilias@nil.foundation>
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//---------------------------------------------------------------------------//

#include <iostream>

#include <nil/crypto3/algebra/fields/detail/element/fp.hpp>
#include <nil/crypto3/algebra/fields/detail/element/fp2.hpp>
#include <nil/crypto3/algebra/fields/detail/element/fp3.hpp>
#include <nil/crypto3/algebra/fields/detail/element/fp4.hpp>
#include <nil/crypto3/algebra/fields/detail/element/fp6_2over3.hpp>
#include <nil/crypto3/algebra/fields/detail/element/fp6_3over2.hpp>
#include <nil/crypto3/algebra/fields/detail/element/fp12_2over3over2.hpp>

#include <nil/crypto3/algebra/curves/bls12.hpp>
#include <nil/crypto3/algebra/curves/mnt4.hpp>
#include <nil/crypto3/algebra/curves/mnt6.hpp>
#include <nil/crypto3/algebra/curves/edwards.hpp>
#include <nil/crypto3/algebra/pairing/bls12.hpp>
#include <nil/crypto3/algebra/pairing/mnt4.hpp>
#include <nil/crypto3/algebra/pairing/mnt6.hpp>
#include <nil/crypto3/algebra/pairing/edwards.hpp>

#include <nil/crypto3/algebra/algorithms/pair.hpp>
#include <nil/crypto3/algebra/random_element.hpp>

using namespace nil::crypto3::algebra;

template<typename FieldParams>
void print_field_element(typename fields::detail::element_fp<FieldParams> e) {
    std::cout << "fp: " << e.data << std::endl;
}

template<typename FieldParams>
void print_field_element(typename fields::detail::element_fp2<FieldParams> e) {
    std::cout << "fp2: " << e.data[0].data << " " << e.data[1].data << std::endl;
}

template<typename FieldParams>
void print_field_element(typename fields::detail::element_fp3<FieldParams> e) {
    std::cout << "fp3: " << e.data[0].data << " " << e.data[1].data << " " << e.data[2].data << std::endl;
}

template<typename FieldParams>
void print_field_element(typename fields::detail::element_fp4<FieldParams> e) {
    std::cout << "fp4: \n";
    print_field_element(e.data[0]);
    print_field_element(e.data[1]);
}

template<typename FieldParams>
void print_field_element(typename fields::detail::element_fp6_2over3<FieldParams> e) {
    std::cout << "fp6_2over3: \n";
    print_field_element(e.data[0]);
    print_field_element(e.data[1]);
}

template<typename FieldParams>
void print_field_element(typename fields::detail::element_fp6_3over2<FieldParams> e) {
    std::cout << "fp6_3over2: \n";
    print_field_element(e.data[0]);
    print_field_element(e.data[1]);
    print_field_element(e.data[2]);
}

template<typename FieldParams>
void print_field_element(typename fields::detail::element_fp12_2over3over2<FieldParams> e) {
    std::cout << "fp12_2over3over2: \n";;
    print_field_element(e.data[0]);
    print_field_element(e.data[1]);
}

template<typename CurveGroupValueType>
void print_curve_group_element(CurveGroupValueType e) {
    std::cout << "Group element: \n";;
    print_field_element(e.X);
    print_field_element(e.Y);
    print_field_element(e.Z);
}

void print_ate_g1_precomp_element(const typename pairing::pairing_policy<curves::bls12<381>>::g1_precomputed_type &e) {
    std::cout << e.PX.data << " " << e.PY.data << std::endl;
}

void print_ate_g2_precomp_element(const pairing::pairing_policy<curves::bls12<381>>::g2_precomputed_type &e) {
    std::cout << "\"coordinates\": [[" << e.QX.data[0].data << " , " << e.QX.data[1].data << "] , ["
              << e.QY.data[0].data << " , " << e.QY.data[1].data << "]]" << std::endl;
    auto print_coeff = [](const auto &c) {
        std::cout << "\"ell_0\": [" << c.ell_0.data[0].data << "," << c.ell_0.data[1].data << "],"
                  << "\"ell_VW\": [" << c.ell_VW.data[0].data << "," << c.ell_VW.data[1].data << "],"
                  << "\"ell_VV\": [" << c.ell_VV.data[0].data << "," << c.ell_VV.data[1].data << "]";
    };
    std::cout << "coefficients: [";
    for (auto &c : e.coeffs) {
        std::cout << "{";
        print_coeff(c);
        std::cout << "},";
    }
    std::cout << "]" << std::endl;
}

void print_ate_g1_precomp_element(const typename pairing::pairing_policy<curves::mnt4<298>>::g1_precomputed_type &e) {
    std::cout << "Ate g1 precomp element:" << std::endl;
    print_field_element(e.PX);
    print_field_element(e.PY);
    print_field_element(e.PX_twist);
    print_field_element(e.PY_twist);
}

void print_ate_g2_precomp_element(const typename pairing::pairing_policy<curves::mnt4<298>>::g2_precomputed_type &e) {
    std::cout << "Ate g2 precomp element:" << std::endl;

    print_field_element(e.QX);
    print_field_element(e.QY);
    print_field_element(e.QY2);
    print_field_element(e.QX_over_twist);
    print_field_element(e.QY_over_twist);

    for (auto &c : e.dbl_coeffs) {
        std::cout << "{";
        print_field_element(c.c_H);
        print_field_element(c.c_4C);
        print_field_element(c.c_J);
        print_field_element(c.c_L);
        std::cout << "},";
    }

    for (auto &c : e.add_coeffs) {
        std::cout << "{";
        print_field_element(c.c_L1);
        print_field_element(c.c_RZ);
        std::cout << "},";
    }
}

void print_ate_g1_precomp_element(const typename pairing::pairing_policy<curves::mnt6<298>>::g1_precomputed_type &e) {
    std::cout << "Ate g1 precomp element:" << std::endl;
    print_field_element(e.PX);
    print_field_element(e.PY);
    print_field_element(e.PX_twist);
    print_field_element(e.PY_twist);
}

void print_ate_g2_precomp_element(const typename pairing::pairing_policy<curves::mnt6<298>>::g2_precomputed_type &e) {
    std::cout << "Ate g2 precomp element:" << std::endl;

    print_field_element(e.QX);
    print_field_element(e.QY);
    print_field_element(e.QY2);
    print_field_element(e.QX_over_twist);
    print_field_element(e.QY_over_twist);

    for (auto &c : e.dbl_coeffs) {
        std::cout << "{";
        print_field_element(c.c_H);
        print_field_element(c.c_4C);
        print_field_element(c.c_J);
        print_field_element(c.c_L);
        std::cout << "},";
    }

    for (auto &c : e.add_coeffs) {
        std::cout << "{";
        print_field_element(c.c_L1);
        print_field_element(c.c_RZ);
        std::cout << "},";
    }
}

template<typename CurveType>
void pairing_example() {
    using curve_type = CurveType;

    using g1_type = typename curve_type::template g1_type<>;
    using g2_type = typename curve_type::template g2_type<>;
    using g1_field_value_type = typename g1_type::field_type::value_type;
    using g2_field_value_type = typename g2_type::field_type::value_type;

    typename curve_type::template g1_type<>::value_type g1_el1 = random_element<typename curve_type::template g1_type<>>();
    std::cout << "g1_el1: ";
    print_curve_group_element(g1_el1);

    typename pairing::pairing_policy<curve_type>::g1_precomputed_type 
        g1_precomp_el1 = precompute_g1<curve_type>(g1_el1);
    std::cout << "g1_precomp_el1: ";
    // print_ate_g1_precomp_element(g1_precomp_el1);

    typename curve_type::template g1_type<>::value_type g1_el2 = g1_type::value_type::one();
    std::cout << "g1_el2: ";
    print_curve_group_element(g1_el2);
    typename pairing::pairing_policy<curve_type>::g1_precomputed_type 
        g1_precomp_el2 = precompute_g1<curve_type>(g1_el2);
    std::cout << "g1_precomp_el2: ";
    // print_ate_g1_precomp_element(g1_precomp_el2);

    typename curve_type::template g2_type<>::value_type g2_el1 = random_element<typename curve_type::template g2_type<>>();
    std::cout << "g2_el1: ";
    print_curve_group_element(g2_el1);
    typename pairing::pairing_policy<curve_type>::g2_precomputed_type 
        g2_precomp_el1 = precompute_g2<curve_type>(g2_el1);
    std::cout << "g2_precomp_el1: ";
    // print_ate_g2_precomp_element(g2_precomp_el1);
    typename curve_type::template g2_type<>::value_type g2_el2 = g2_type::value_type::one();
    std::cout << "g2_el2: ";
    print_curve_group_element(g2_el2);
    typename pairing::pairing_policy<curve_type>::g2_precomputed_type 
        g2_precomp_el2 = precompute_g2<curve_type>(g2_el2);
    std::cout << "g2_precomp_el2: ";
    // print_ate_g2_precomp_element(g2_precomp_el2);

    typename curve_type::gt_type::value_type gt_el1 = pair_reduced<curve_type>(g1_el1, g2_el1);
    std::cout << "gt_el1: ";
    print_field_element(gt_el1);

    typename curve_type::gt_type::value_type gt_el2 = pair<curve_type>(g1_el1, g2_el1);
    std::cout << "gt_el2: ";
    print_field_element(gt_el2);

    typename curve_type::gt_type::value_type gt_el3 = miller_loop<curve_type>(g1_precomp_el1, g2_precomp_el1);
    std::cout << "gt_el3: ";
    print_field_element(gt_el3);

    typename curve_type::gt_type::value_type gt_el4 =
        double_miller_loop<curve_type>(g1_precomp_el1, g2_precomp_el1, g1_precomp_el2, g2_precomp_el2);
    std::cout << "gt_el4: ";
    print_field_element(gt_el4);

    typename curve_type::gt_type::value_type gt_el5 = final_exponentiation<curve_type>(gt_el4);
    std::cout << "gt_el5: ";
    print_field_element(gt_el5);
}

int main() {
    pairing_example<curves::bls12<381>>();

    pairing_example<curves::mnt4<298>>();

    pairing_example<curves::mnt6<298>>();

    pairing_example<curves::edwards<183>>();
}
