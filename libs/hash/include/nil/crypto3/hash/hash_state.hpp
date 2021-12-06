//---------------------------------------------------------------------------//
// Copyright (c) 2018-2020 Mikhail Komarov <nemo@nil.foundation>
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

#ifndef CRYPTO3_HASH_STATE_HPP
#define CRYPTO3_HASH_STATE_HPP

#include <boost/accumulators/framework/accumulator_set.hpp>
#include <boost/accumulators/framework/features.hpp>

#include <nil/crypto3/detail/type_traits.hpp>

#include <nil/crypto3/hash/accumulators/hash.hpp>

#include <nil/crypto3/detail/static_digest.hpp>

namespace nil {
    namespace crypto3 {
        template<typename Hash, typename = typename std::enable_if<detail::is_hash<Hash>::value>::type>
        struct accumulator_set
            : public boost::accumulators::accumulator_set<static_digest<Hash::digest_bits>,
                                                          boost::accumulators::features<accumulators::tag::hash<Hash>>,
                                                          std::size_t> {
            typedef Hash hash_type;
        };
    }    // namespace crypto3
}    // namespace nil

#endif    // CRYPTO3_BLOCK_STREAM_PREPROCESSOR_HPP