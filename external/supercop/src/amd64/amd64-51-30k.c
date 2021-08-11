// Copyright (c) 2020, The Liberty Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Parts of this file from bench.cr.yp.to/supercop.html (2017-07-25):
//     Daniel J. Bernstein
//     Niels Duif
//     Tanja Lange
//     lead: Peter Schwabe
//     Bo-Yin Yang

#include <stddef.h>
#include "fe25519.h"

/* constants below can be found in various fles in ed25519/amd64-51-30k */

/* d */
static const fe25519 ecd = {{929955233495203, 466365720129213, 1662059464998953, 2033849074728123, 1442794654840575}};
/* 2*d */
static const fe25519 ec2d = {{1859910466990425, 932731440258426, 1072319116312658, 1815898335770999, 633789495995903}};
/* sqrt(-1) */
static const fe25519 sqrtm1 = {{1718705420411056, 234908883556509, 2233514472574048, 2117202627021982, 765476049583133}};

#define choose_tp crypto_sign_ed25519_amd64_51_30k_batch_choose_tp
#include "amd64.c.inc"

int liberty_crypto_amd64_51_30k_ge25519_scalarmult(char* out, char const* pub, char const* sec)
{
  return scalarmult(out, pub, sec);
}

int liberty_crypto_amd64_51_30k_generate_key_derivation(char* out, char const* tx_pub, char const* view_sec)
{
  return generate_key_derivation(out, tx_pub, view_sec);
}

int liberty_crypto_amd64_51_30k_generate_subaddress_public_key(char* out, char const* output_pub, char const* special_sec)
{
  return generate_subaddress_public_key(out, output_pub, special_sec);
}

