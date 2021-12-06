//---------------------------------------------------------------------------//
// Copyright (c) 2017-2021 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020-2021 Nikita Kaskov <nbering@nil.foundation>
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

#ifndef CRYPTO3_MARSHALLING_SPARSE_VECTOR_HPP
#define CRYPTO3_MARSHALLING_SPARSE_VECTOR_HPP

#include <ratio>
#include <limits>
#include <type_traits>

#include <nil/marshalling/types/bundle.hpp>
#include <nil/marshalling/types/array_list.hpp>
#include <nil/marshalling/types/integral.hpp>
#include <nil/marshalling/types/tag.hpp>
#include <nil/marshalling/types/detail/adapt_basic_field.hpp>
#include <nil/marshalling/status_type.hpp>
#include <nil/marshalling/options.hpp>

#include <nil/crypto3/algebra/type_traits.hpp>

#include <nil/crypto3/zk/snark/sparse_vector.hpp>

#include <nil/crypto3/marshalling/types/algebra/curve_element.hpp>

namespace nil {
    namespace crypto3 {
        namespace marshalling {
            namespace types {
                template<typename TTypeBase,
                         typename SparseVector,
                         typename = typename std::enable_if<
                             std::is_same<SparseVector, 
                                zk::snark::sparse_vector<
                                    typename SparseVector::group_type
                                >
                             >::value,
                             bool>::type,
                         typename... TOptions>
                using sparse_vector = 
                    nil::marshalling::types::bundle<
                        TTypeBase,
                        std::tuple<
                            nil::marshalling::types::array_list<
                                TTypeBase,
                                nil::marshalling::types::integral<
                                    TTypeBase, 
                                    std::size_t
                                >,
                                nil::marshalling::option::sequence_size_field_prefix<
                                    nil::marshalling::types::integral<
                                        TTypeBase, 
                                        std::size_t
                                    >
                                > 
                            >, 
                            nil::marshalling::types::array_list<
                                TTypeBase,
                                curve_element<
                                    TTypeBase, 
                                    typename SparseVector::group_type
                                >,
                                nil::marshalling::option::sequence_size_field_prefix<
                                    nil::marshalling::types::integral<
                                        TTypeBase, 
                                        std::size_t
                                    >
                                > 
                            >,
                            nil::marshalling::types::integral<
                                TTypeBase, 
                                std::size_t
                            > 
                        >
                    >;

                template <typename SparseVector, 
                          typename Endianness>
                sparse_vector<nil::marshalling::field_type<
                                Endianness>,
                                SparseVector>
                    fill_sparse_vector(SparseVector sparse_vector_inp){

                    using TTypeBase = nil::marshalling::field_type<
                                Endianness>;

                    using integral_type = 
                        nil::marshalling::types::integral<
                            TTypeBase,
                            std::size_t
                        >;
                    using integral_vector_type = 
                        nil::marshalling::types::array_list<
                            TTypeBase,
                            integral_type,
                            nil::marshalling::option::sequence_size_field_prefix<
                                integral_type
                            > 
                        >;

                    integral_vector_type filled_indices;

                    std::vector<integral_type> &filled_indices_val = filled_indices.value();
                    for (std::size_t i=0; 
                         i<sparse_vector_inp.indices.size();
                         i++){
                        filled_indices_val.push_back(integral_type(
                            sparse_vector_inp.indices[i]));
                    }

                    return sparse_vector<nil::marshalling::field_type<
                                Endianness>,
                                SparseVector>(
                                    std::make_tuple(
                                        filled_indices,
                                        fill_curve_element_vector<
                                            typename SparseVector::group_type, 
                                            Endianness>(sparse_vector_inp.values),
                                        integral_type(sparse_vector_inp.domain_size_)));
                }

                template <typename SparseVector, 
                          typename Endianness>
                SparseVector make_sparse_vector(
                        sparse_vector<nil::marshalling::field_type<
                                Endianness>,
                                SparseVector> filled_sparse_vector){

                    using TTypeBase = nil::marshalling::field_type<
                                Endianness>;

                    using integral_type = 
                        nil::marshalling::types::integral<
                            TTypeBase,
                            std::size_t
                        >;

                    std::vector<std::size_t> constructed_indices;
                    std::vector<integral_type> &filled_indices = 
                        std::get<0>(filled_sparse_vector.value()).value();
                    std::size_t size = filled_indices.size();

                    for (std::size_t i=0; 
                         i<size;
                         i++){
                        constructed_indices.push_back(
                            filled_indices[i].value());
                    }

                    SparseVector result;
                    result.indices = constructed_indices;
                    result.values = make_curve_element_vector<typename SparseVector::group_type, Endianness>(
                        std::get<1>(filled_sparse_vector.value()));
                    result.domain_size_ = 
                        std::get<2>(filled_sparse_vector.value()).value();

                    return result;
                }

            }    // namespace types
        }        // namespace marshalling
    }        // namespace crypto3
}    // namespace nil
#endif    // CRYPTO3_MARSHALLING_SPARSE_VECTOR_HPP
