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
#include <string.h>
#define VEC_SIZE 256
#define aa(p, n) (a[(p)*VEC_SIZE + (n)])
#define bb(p, n) (b[(p)*VEC_SIZE + (n)])
#define cc(p, n) (c[(p)*VEC_SIZE + (n)])

void mars_kernel_1_0_0_node_0_stage_0(int k, int exec, float *a,
                                      float a_2_0_buf[256]) {

#pragma HLS INLINE OFF
#pragma HLS array_partition variable = a_2_0_buf cyclic factor = 8
  if (exec == 1) {
    memcpy(((void *)(&a_2_0_buf[0])), ((const void *)(&a[256 * k])),
           sizeof(float) * ((unsigned long)256));
  }
}

void mars_kernel_1_0_0_node_1_stage_0(int k, int exec, float *b,
                                      float b_2_0_buf[256]) {

#pragma HLS INLINE OFF
  if (exec == 1) {
    memcpy(((void *)(&b_2_0_buf[0])), ((const void *)(&b[256 * k])),
           sizeof(float) * ((unsigned long)256));
  }
}

void mars_kernel_1_0_0_node_2_stage_1(int k, int exec, float a_2_0_buf[256],
                                      float b_2_0_buf[256],
                                      float c_2_0_buf[65536]) {
  int j;
  int i;

#pragma HLS INLINE OFF
  if (exec == 1) {
    for (i = 0; i < 256; i++) {

#pragma ACCEL pipeline
      for (j = 0; j < 256; j++) {

#pragma ACCEL parallel complete
        c_2_0_buf[256 * i + j] += a_2_0_buf[i * j] * b_2_0_buf[j];
      }
    }
  }
}

void mars_kernel_1_0_0_assign_a_2_0_buf(float target[256], float orig[256]) {
  int i0;
  for (i0 = 0; i0 < 256; i0++) {
    target[i0] = orig[i0];
  }
}

void mars_kernel_1_0_0_assign_b_2_0_buf(float target[256], float orig[256]) {
  int i0;
  for (i0 = 0; i0 < 256; i0++) {
    target[i0] = orig[i0];
  }
}

void mars_kernel_1_0_0_assign_c_2_0_buf(float target[65536],
                                        float orig[65536]) {
  int i0;
  for (i0 = 0; i0 < 65536; i0++) {
    target[i0] = orig[i0];
  }
}

void mars_kernel_1_0_0(int mars_k, int mars_init, int mars_cond, float *a,
                       float mars_a_2_0_buf_0[256], float mars_a_2_0_buf_1[256],
                       float *b, float mars_b_2_0_buf_0[256],
                       float mars_b_2_0_buf_1[256],
                       float mars_c_2_0_buf_1[65536]) {
  mars_kernel_1_0_0_node_0_stage_0(
      mars_k - 0, mars_k >= mars_init + 0 && mars_k < mars_cond + 0, a,
      mars_a_2_0_buf_0);
  mars_kernel_1_0_0_node_1_stage_0(
      mars_k - 0, mars_k >= mars_init + 0 && mars_k < mars_cond + 0, b,
      mars_b_2_0_buf_0);
  mars_kernel_1_0_0_node_2_stage_1(
      mars_k - 1, mars_k >= mars_init + 1 && mars_k < mars_cond + 1,
      mars_a_2_0_buf_1, mars_b_2_0_buf_1, mars_c_2_0_buf_1);
}
#pragma ACCEL kernel
void matmul_kernel(float *a, float *b, float *c) {
  float mars_kernel_1_0_0_b_2_0_buf_1[256];
  float mars_kernel_1_0_0_b_2_0_buf_0[256];
  float mars_kernel_1_0_0_a_2_0_buf_1[256];
  float mars_kernel_1_0_0_a_2_0_buf_0[256];
  float c_2_0_buf[65536];
  float b_2_0_buf[256];
  float a_2_0_buf[256];
  int i;
  int j;
  int k;
#pragma HLS array_partition variable = c_2_0_buf cyclic factor = 16
  memcpy((&c_2_0_buf[0]), (&c[0]), sizeof(float) * 65536);
  int mars_count_1_0_0 = 0;
  mars_kernel_1_0_0_assign_a_2_0_buf(mars_kernel_1_0_0_a_2_0_buf_0, a_2_0_buf);
  mars_kernel_1_0_0_assign_a_2_0_buf(mars_kernel_1_0_0_a_2_0_buf_1, a_2_0_buf);
  mars_kernel_1_0_0_assign_b_2_0_buf(mars_kernel_1_0_0_b_2_0_buf_0, b_2_0_buf);
  mars_kernel_1_0_0_assign_b_2_0_buf(mars_kernel_1_0_0_b_2_0_buf_1, b_2_0_buf);
  for (k = 0; k < 256 + 1; k++)
  // Original: #pragma ACCEL pipeline
  {
#pragma HLS array_partition variable = a_2_0_buf cyclic factor = 16
#pragma HLS array_partition variable = b_2_0_buf cyclic factor = 16
    if (mars_count_1_0_0 == 0)
      mars_kernel_1_0_0(k, 0, 256, a, mars_kernel_1_0_0_a_2_0_buf_0,
                        mars_kernel_1_0_0_a_2_0_buf_1, b,
                        mars_kernel_1_0_0_b_2_0_buf_0,
                        mars_kernel_1_0_0_b_2_0_buf_1, c_2_0_buf);
    else if (mars_count_1_0_0 == 1)
      mars_kernel_1_0_0(k, 0, 256, a, mars_kernel_1_0_0_a_2_0_buf_1,
                        mars_kernel_1_0_0_a_2_0_buf_0, b,
                        mars_kernel_1_0_0_b_2_0_buf_1,
                        mars_kernel_1_0_0_b_2_0_buf_0, c_2_0_buf);
    mars_count_1_0_0++;
    if (mars_count_1_0_0 == 2)
      mars_count_1_0_0 = 0;
  }
  mars_kernel_1_0_0_assign_b_2_0_buf(b_2_0_buf, mars_kernel_1_0_0_b_2_0_buf_1);
  mars_kernel_1_0_0_assign_b_2_0_buf(b_2_0_buf, mars_kernel_1_0_0_b_2_0_buf_0);
  mars_kernel_1_0_0_assign_a_2_0_buf(a_2_0_buf, mars_kernel_1_0_0_a_2_0_buf_1);
  mars_kernel_1_0_0_assign_a_2_0_buf(a_2_0_buf, mars_kernel_1_0_0_a_2_0_buf_0);
#pragma HLS array_partition variable = c_2_0_buf cyclic factor = 16
  memcpy((&c[0]), (&c_2_0_buf[0]), sizeof(float) * 65536);
}
