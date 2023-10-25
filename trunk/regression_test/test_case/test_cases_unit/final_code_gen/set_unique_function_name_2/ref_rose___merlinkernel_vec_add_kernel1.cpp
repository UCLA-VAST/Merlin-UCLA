//(C) Copyright 2016-2021 Xilinx, Inc.
//All Rights Reserved.
//
//Licensed to the Apache Software Foundation (ASF) under one
//or more contributor license agreements.  See the NOTICE file
//distributed with this work for additional information
//regarding copyright ownership.  The ASF licenses this file
//to you under the Apache License, Version 2.0 (the
//"License"); you may not use this file except in compliance
//with the License.  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing,
//software distributed under the License is distributed on an
//"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
//KIND, either express or implied.  See the License for the
//specific language governing permissions and limitations
//under the License. (edited)
#include "memcpy_512_1d.h"
#define SIZE_1 16
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 
#include "cmost.h"
#include "merlin_type_define.h"
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_kernel_pragma();
// Original: #pragma ACCEL kernel die=SLR0
static int vec_add_kernel1_dummy_pos;
extern "C" { 

__kernel void vec_add_kernel1(::merlin_uint_512 *a,::merlin_uint_512 *b,::merlin_uint_512 *c,int inc)
{
  
#pragma HLS INTERFACE m_axi port=a offset=slave depth=625 bundle=merlin_gmem_vec_add_kernel1_512_0
  
#pragma HLS INTERFACE m_axi port=b offset=slave depth=625 bundle=merlin_gmem_vec_add_kernel1_512_1
  
#pragma HLS INTERFACE m_axi port=c offset=slave depth=625 bundle=merlin_gmem_vec_add_kernel1_512_0
  
#pragma HLS INTERFACE s_axilite port=a bundle=control
  
#pragma HLS INTERFACE s_axilite port=b bundle=control
  
#pragma HLS INTERFACE s_axilite port=c bundle=control
  
#pragma HLS INTERFACE s_axilite port=inc bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=c
  
#pragma HLS DATA_PACK VARIABLE=b
  
#pragma HLS DATA_PACK VARIABLE=a
  int b_buf_0[625][16];
// Existing HLS partition: #pragma HLS array_partition variable=b_buf_0 cyclic factor = 16 dim=2
  
#pragma HLS array_partition variable=b_buf_0 complete dim=2
  memcpy_wide_bus_read_int_2d_16_512(b_buf_0,0,0,(::merlin_uint_512 *)b,(0 * 4),sizeof(int ) * ((unsigned long )10000),10000L);
  int a_buf_0[625][16];
// Existing HLS partition: #pragma HLS array_partition variable=a_buf_0 cyclic factor = 16 dim=2
  
#pragma HLS array_partition variable=a_buf_0 complete dim=2
  memcpy_wide_bus_read_int_2d_16_512(a_buf_0,0,0,(::merlin_uint_512 *)a,(0 * 4),sizeof(int ) * ((unsigned long )10000),10000L);
  int c_buf_0[625][16];
  
#pragma HLS array_partition variable=c_buf_0 complete dim=2
  
#pragma ACCEL interface variable=a max_depth=10000 depth=10000
  
#pragma ACCEL interface variable=b max_depth=10000 depth=10000
  
#pragma ACCEL interface variable=c max_depth=10000 depth=10000
  int j;
  int j0;
  int jj;
  merlinL1:
  for (j0 = 0; j0 < 10000 / 16; j0++) 
// Original: #pragma ACCEL PIPELINE AUTO
{
    
#pragma HLS pipeline
    merlinL0:
    for (jj = 0; jj < 16; jj++) 
// Original: #pragma ACCEL parallel
// Original: #pragma ACCEL PARALLEL COMPLETE
// Original: #pragma ACCEL PARALLEL COMPLETE
{
      
#pragma HLS unroll
      j = j0 * 16 + jj;
      c_buf_0[j0][jj] = a_buf_0[j0][jj] + b_buf_0[j0][jj] + inc;
    }
  }
// Existing HLS partition: #pragma HLS array_partition variable=c_buf_0 cyclic factor = 16 dim=2
  memcpy_wide_bus_write_int_2d_16_512((::merlin_uint_512 *)c,c_buf_0,0,0,(4 * 0),sizeof(int ) * ((unsigned long )10000),10000L);
}
}
