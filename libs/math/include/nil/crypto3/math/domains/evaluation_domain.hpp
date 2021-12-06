//---------------------------------------------------------------------------//
// Copyright (c) 2020 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020 Nikita Kaskov <nbering@nil.foundation>
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

#ifndef CRYPTO3_MATH_EVALUATION_DOMAIN_HPP
#define CRYPTO3_MATH_EVALUATION_DOMAIN_HPP

#include <vector>

#include <nil/crypto3/multiprecision/integer.hpp>

namespace nil {
    namespace crypto3 {
        namespace math {

            /**
             * An evaluation domain.
             */
            template<typename FieldType>
            class evaluation_domain {

                typedef typename FieldType::value_type value_type;

            public:
                value_type root;
                value_type root_inverse;
                value_type domain;
                value_type domain_inverse;
                value_type generator;
                value_type generator_inverse;

                std::size_t m;
                std::size_t log2_size;
                std::size_t generator_size;

                /**
                 * Construct an evaluation domain S of size m, if possible.
                 *
                 * (See the function get_evaluation_domain below.)
                 */
                evaluation_domain(const std::size_t m) : m(m), log2_size(multiprecision::msb(m)) {};

                /**
                 * Get the idx-th element in S.
                 */
                virtual value_type get_domain_element(const std::size_t idx) = 0;

                /**
                 * Compute the FFT, over the domain S, of the vector a.
                 */
                virtual void fft(std::vector<value_type> &a) = 0;

                /**
                 * Compute the inverse FFT, over the domain S, of the vector a.
                 */
                virtual void inverse_fft(std::vector<value_type> &a) = 0;

                /**
                 * Evaluate all Lagrange polynomials.
                 *
                 * The inputs are:
                 * - an integer m
                 * - an element t
                 * The output is a vector (b_{0},...,b_{m-1})
                 * where b_{i} is the evaluation of L_{i,S}(z) at z = t.
                 */
                virtual std::vector<value_type> evaluate_all_lagrange_polynomials(const value_type &t) = 0;

                /**
                 * Evaluate the vanishing polynomial of S at the field element t.
                 */
                virtual value_type compute_vanishing_polynomial(const value_type &t) = 0;

                /**
                 * Add the coefficients of the vanishing polynomial of S to the coefficients of the polynomial H.
                 */
                virtual void add_poly_z(const value_type &coeff, std::vector<value_type> &H) = 0;

                /**
                 * Multiply by the evaluation, on a coset of S, of the inverse of the vanishing polynomial of S.
                 */
                virtual void divide_by_z_on_coset(std::vector<value_type> &P) = 0;
            };
        }    // namespace math
    }        // namespace crypto3
}    // namespace nil

#endif    // ALGEBRA_FFT_EVALUATION_DOMAIN_HPP
