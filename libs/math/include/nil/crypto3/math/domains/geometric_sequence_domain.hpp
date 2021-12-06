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

#ifndef CRYPTO3_MATH_GEOMETRIC_SEQUENCE_DOMAIN_HPP
#define CRYPTO3_MATH_GEOMETRIC_SEQUENCE_DOMAIN_HPP

#include <vector>

#include <nil/crypto3/math/domains/evaluation_domain.hpp>

#include <nil/crypto3/math/polynomial/basis_change.hpp>

#ifdef MULTICORE
#include <omp.h>
#endif

namespace nil {
    namespace crypto3 {
        namespace math {

            using namespace nil::crypto3::algebra;

            template<typename FieldType>
            class evaluation_domain;

            template<typename FieldType>
            class geometric_sequence_domain : public evaluation_domain<FieldType> {
                typedef typename FieldType::value_type value_type;

            public:
                bool precomputation_sentinel;
                std::vector<value_type> geometric_sequence;
                std::vector<value_type> geometric_triangular_sequence;

                void do_precomputation() {
                    geometric_sequence = std::vector<value_type>(this->m, value_type::zero());
                    geometric_sequence[0] = value_type::one();

                    geometric_triangular_sequence = std::vector<value_type>(this->m, value_type::zero());
                    geometric_triangular_sequence[0] = value_type::one();

                    for (std::size_t i = 1; i < this->m; i++) {
                        geometric_sequence[i] =
                            geometric_sequence[i - 1] * fields::arithmetic_params<FieldType>::geometric_generator;
                        geometric_triangular_sequence[i] =
                            geometric_triangular_sequence[i - 1] * geometric_sequence[i - 1];
                    }

                    precomputation_sentinel = true;
                }

                geometric_sequence_domain(const std::size_t m) : evaluation_domain<FieldType>(m) {
                    if (m <= 1) {
                        throw std::invalid_argument("geometric(): expected m > 1");
                    }

                    if (value_type(fields::arithmetic_params<FieldType>::geometric_generator).is_zero()) {
                        throw std::invalid_argument(
                            "geometric(): expected "
                            "value_type(fields::arithmetic_params<FieldType>::geometric_generator).is_zero() != "
                            "true");
                    }

                    precomputation_sentinel = false;
                }

                void fft(std::vector<value_type> &a) {
                    if (a.size() != this->m)
                        throw std::invalid_argument("geometric: expected a.size() == this->m");

                    if (!precomputation_sentinel)
                        do_precomputation();

                    monomial_to_newton_basis_geometric<FieldType>(a, geometric_sequence, geometric_triangular_sequence,
                                                                  this->m);

                    /* Newton to Evaluation */
                    std::vector<value_type> T(this->m);
                    T[0] = value_type::one();

                    std::vector<value_type> g(this->m);
                    g[0] = a[0];

                    for (std::size_t i = 1; i < this->m; i++) {
                        T[i] = T[i - 1] * (geometric_sequence[i] - value_type::one()).inversed();
                        g[i] = geometric_triangular_sequence[i] * a[i];
                    }

                    _polynomial_multiplication<FieldType>(a, g, T);
                    a.resize(this->m);

#ifdef MULTICORE
#pragma omp parallel for
#endif
                    for (std::size_t i = 0; i < this->m; i++) {
                        a[i] *= T[i].inversed();
                    }
                }
                void inverse_fft(std::vector<value_type> &a) {
                    if (a.size() != this->m)
                        throw std::invalid_argument("geometric: expected a.size() == this->m");

                    if (!precomputation_sentinel)
                        do_precomputation();

                    /* Interpolation to Newton */
                    std::vector<value_type> T(this->m);
                    T[0] = value_type::one();

                    std::vector<value_type> W(this->m);
                    W[0] = a[0] * T[0];

                    value_type prev_T = T[0];
                    for (std::size_t i = 1; i < this->m; i++) {
                        prev_T *= (geometric_sequence[i] - value_type::one()).inversed();

                        W[i] = a[i] * prev_T;
                        T[i] = geometric_triangular_sequence[i] * prev_T;
                        if (i % 2 == 1)
                            T[i] = -T[i];
                    }

                    _polynomial_multiplication<FieldType>(a, W, T);
                    a.resize(this->m);

#ifdef MULTICORE
#pragma omp parallel for
#endif
                    for (std::size_t i = 0; i < this->m; i++) {
                        a[i] *= geometric_triangular_sequence[i].inversed();
                    }

                    newton_to_monomial_basis_geometric<FieldType>(a, geometric_sequence, geometric_triangular_sequence,
                                                                  this->m);
                }
                std::vector<value_type> evaluate_all_lagrange_polynomials(const value_type &t) {
                    /* Compute Lagrange polynomial of size m, with m+1 points (x_0, y_0), ... ,(x_m, y_m) */
                    /* Evaluate for x = t */
                    /* Return coeffs for each l_j(x) = (l / l_i[j]) * w[j] */

                    /* for all i: w[i] = (1 / r) * w[i-1] * (1 - a[i]^m-i+1) / (1 - a[i]^-i) */

                    if (!precomputation_sentinel) {
                        do_precomputation();
                    }

                    /**
                     * If t equals one of the geometric progression values,
                     * then output 1 at the right place, and 0 elsewhere.
                     */
                    for (std::size_t i = 0; i < this->m; ++i) {
                        if (geometric_sequence[i] == t)    // i.e., t equals a[i]
                        {
                            std::vector<value_type> res(this->m, value_type::zero());
                            res[i] = value_type::one();
                            return res;
                        }
                    }

                    /**
                     * Otherwise, if t does not equal any of the geometric progression values,
                     * then compute each Lagrange coefficient.
                     */
                    std::vector<value_type> l(this->m);
                    l[0] = t - geometric_sequence[0];

                    std::vector<value_type> g(this->m);
                    g[0] = value_type::zero();

                    value_type l_vanish = l[0];
                    value_type g_vanish = value_type::one();
                    for (std::size_t i = 1; i < this->m; i++) {
                        l[i] = t - geometric_sequence[i];
                        g[i] = value_type::one() - geometric_sequence[i];

                        l_vanish *= l[i];
                        g_vanish *= g[i];
                    }

                    value_type r = geometric_sequence[this->m - 1].inversed();
                    value_type r_i = r;

                    std::vector<value_type> g_i(this->m);
                    g_i[0] = g_vanish.inversed();

                    l[0] = l_vanish * l[0].inversed() * g_i[0];
                    for (std::size_t i = 1; i < this->m; i++) {
                        g_i[i] = g_i[i - 1] * g[this->m - i] * -g[i].inversed() * geometric_sequence[i];
                        l[i] = l_vanish * r_i * l[i].inversed() * g_i[i];
                        r_i *= r;
                    }

                    return l;
                }
                value_type get_domain_element(const std::size_t idx) {
                    if (!precomputation_sentinel)
                        do_precomputation();

                    return this->geometric_sequence[idx];
                }
                value_type compute_vanishing_polynomial(const value_type &t) {
                    if (!precomputation_sentinel)
                        do_precomputation();

                    /* Notes: Z = prod_{i = 0 to m} (t - a[i]) */
                    /* Better approach: Montgomery Trick + Divide&Conquer/FFT */
                    value_type Z = value_type::one();
                    for (std::size_t i = 0; i < this->m; i++) {
                        Z *= (t - geometric_sequence[i]);
                    }
                    return Z;
                }
                void add_poly_z(const value_type &coeff, std::vector<value_type> &H) {
                    if (H.size() != this->m + 1)
                        throw std::invalid_argument("geometric: expected H.size() == this->m+1");

                    if (!precomputation_sentinel)
                        do_precomputation();

                    std::vector<value_type> x(2, value_type::zero());
                    x[0] = -geometric_sequence[0];
                    x[1] = value_type::one();

                    std::vector<value_type> t(2, value_type::zero());

                    for (std::size_t i = 1; i < this->m + 1; i++) {
                        t[0] = -geometric_sequence[i];
                        t[1] = value_type::one();

                        _polynomial_multiplication<FieldType>(x, x, t);
                    }

#ifdef MULTICORE
#pragma omp parallel for
#endif
                    for (std::size_t i = 0; i < this->m + 1; i++) {
                        H[i] += (x[i] * coeff);
                    }
                }
                void divide_by_z_on_coset(std::vector<value_type> &P) {
                    const value_type coset = value_type(
                        fields::arithmetic_params<FieldType>::multiplicative_generator); /* coset in geometric
                                                                                            sequence? */
                    const value_type Z_inverse_at_coset = compute_vanishing_polynomial(coset).inversed();
                    for (std::size_t i = 0; i < this->m; ++i) {
                        P[i] *= Z_inverse_at_coset;
                    }
                }
            };
        }    // namespace math
    }        // namespace crypto3
}    // namespace nil

#endif    // ALGEBRA_FFT_GEOMETRIC_SEQUENCE_DOMAIN_HPP
