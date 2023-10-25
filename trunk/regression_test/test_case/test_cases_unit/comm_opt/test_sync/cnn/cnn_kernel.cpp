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
#include "config.h"
#pragma ACCEL kernel
void CONV(float *Cout,float *Cin,float *weight,float *bias)
{
  float Cin_buf_0_rf0[226][226][4];
  int _memcpy_i2_2;
  int _memcpy_i2_1;
  int _memcpy_i2_0;
  int _memcpy_i0_2;
  int _memcpy_i0_1;
  int _memcpy_i0_0;
  float Cout_buf[224][224][4];
  float Cout_buf_tmp_0[4];
  float Weight_buf_0[3][3][4][4];
  float Cin_buf_0[226][226][4];
  float Cin_buf_tmp_0[226][226][4];
  int __memcpy_i_1_0;
  for (int i0 = 0; i0 < 512 / 4; i0++) {
    for (int j0 = 0; j0 < 512 / 4; j0++) {
      for (_memcpy_i0_2 = 0; _memcpy_i0_2 < 226; ++_memcpy_i0_2) {
        for (_memcpy_i0_1 = 0; _memcpy_i0_1 < 226; ++_memcpy_i0_1) {
          for (_memcpy_i0_0 = 0; _memcpy_i0_0 < 4; ++_memcpy_i0_0) {
            Cin_buf_0[_memcpy_i0_2][_memcpy_i0_1][_memcpy_i0_0] = Cin[j0 * 4 * 226 * 226 + (((0 * 4 + _memcpy_i0_2) * 226 + _memcpy_i0_1) * 226 + _memcpy_i0_0)];
          }
        }
      }
      for (int ii = 0; ii < 4; ii++) {
        for (int jj = 0; jj < 4; jj++) {
          for (__memcpy_i_1_0 = 0; __memcpy_i_1_0 < sizeof(float ) * ((unsigned long )3) * ((unsigned long )3) / 4; ++__memcpy_i_1_0) {
            Weight_buf_0[(__memcpy_i_1_0 + ii) / 4 / 4 / 3][(__memcpy_i_1_0 + jj) / 4 / 4 % 3][(__memcpy_i_1_0 + 0) / 4 % 4][(__memcpy_i_1_0 + 0) % 4] = weight[__memcpy_i_1_0 + ((i0 * 4 + ii) * 512 * 3 * 3 + (j0 * 4 + jj) * 3 * 3)];
          }
        }
      }
      for (int p = 0; p < 3; p++) {
        for (int q = 0; q < 3; q++) {
          for (int h = 0; h < 226; h++) {
            for (int w = 0; w < 226; w++) 
// Original: #pragma ACCEL pipeline flatten
{
              
#pragma ACCEL PIPELINE II=1
              for (int ii = 0; ii < 4; ii++) {
                if (p == 0 && q == 0) {
                  Cin_buf_0_rf0[h][w][ii] = Cin_buf_0[h][w][ii];
                }
                
#pragma ACCEL PARALLEL COMPLETE
//Cin_buf_tmp[ii][h][w] = Cin_buf[ii][h][w];
                Cin_buf_tmp_0[h][w][ii] = Cin_buf_0_rf0[h][w][ii];
              }
              if (h >= 3 - 1 && w >= 3 - 1) {
                for (int ii = 0; ii < 4; ii++) {
                  
#pragma ACCEL PARALLEL COMPLETE
                  if (p == 0 && q == 0 && j0 == 0) {
                    Cout_buf_tmp_0[ii] = bias[i0 * 4 + ii];
                  }
                   else {
//Cout_buf_tmp[ii] = Cout_buf[ii][h - KERNEL + 1][w - KERNEL + 1];
                    Cout_buf_tmp_0[ii] = Cout_buf[h - 3 + 1][w - 3 + 1][ii];
                  }
                }
                for (int jj = 0; jj < 4; jj++) {
                  
#pragma ACCEL PARALLEL COMPLETE
                  for (int ii = 0; ii < 4; ii++) {
                    
#pragma ACCEL PARALLEL COMPLETE
                    Cout_buf_tmp_0[ii] += Weight_buf_0[ii][jj][p][q] * Cin_buf_tmp_0[jj][h + p - 3 + 1][w + q - 3 + 1];
                  }
                }
                for (int ii = 0; ii < 4; ii++) {
                  
#pragma ACCEL PARALLEL COMPLETE
                  Cout_buf[h - 3 + 1][w - 3 + 1][ii] = Cout_buf_tmp_0[ii];
                }
              }
            }
          }
        }
      }
    }
    for (_memcpy_i2_2 = 0; _memcpy_i2_2 < 224; ++_memcpy_i2_2) {
      for (_memcpy_i2_1 = 0; _memcpy_i2_1 < 224; ++_memcpy_i2_1) {
        for (_memcpy_i2_0 = 0; _memcpy_i2_0 < 4; ++_memcpy_i2_0) {
          Cout[i0 * 4 * 224 * 224 + (((0 * 4 + _memcpy_i2_2) * 224 + _memcpy_i2_1) * 224 + _memcpy_i2_0)] = Cout_buf[_memcpy_i2_2][_memcpy_i2_1][_memcpy_i2_0];
        }
      }
    }
  }
}
