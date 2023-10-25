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
#include<string.h>
#include "logistic.h"
//1. split input global_data to global_data and global_data2
//2. input global_weight, global gradient array index sequence changed
//3. directly transfer weight and gradient instead of shift-register
//void recv_data( volatile float *global_data, unsigned int offset, float data[32][784] )
//{
//    memcpy( *data, (void*)(global_data + offset), 784*32*4 );
//}
//
//void recv_data2( volatile float *global_data2, unsigned int offset, float data2[32][16] )
//{
//    memcpy( *data2, (void*)(global_data2 + offset), 16*32*4 );
//}
//void compute1( float data[32][784], float weights[784+1][16], float result1[32][16] )

void compute1(float data[32][784],float *global_weights,float *global_weights_2,float result1[32][16])
{
  int i;
  int j;
  int k;
  for (j = 0; j < 32; j++) {
    for (k = 0; k < 16; k++) 
/* Original: #pragma ACCEL parallel */
{
      
#pragma ACCEL PARALLEL COMPLETE
      result1[j][k] = global_weights_2[k];
    }
  }
  for (i = 0; i < 784; i++) {
    for (j = 0; j < 32; j++) {
      for (k = 0; k < 16; k++) 
/* Original: #pragma ACCEL parallel */
{
        
#pragma ACCEL PARALLEL COMPLETE
//result1[j][k] += weights[i+1][k] * data[j][i];
        result1[j][k] += global_weights[k * 784 + i] * data[j][i];
      }
    }
  }
}

void compute2(float result1[32][16],float data2[32][16],float result2[32][16])
{
  int j;
  int k;
  float result1_t_0;
  float temp_0;
  for (j = 0; j < 32; j++) {
    for (k = 0; k < 16; k++) 
/* Original: #pragma ACCEL parallel */
{
      
#pragma ACCEL PARALLEL COMPLETE
      result1_t_0 = result1[j][k];
      temp_0 = 1 + result1_t_0 * result1_t_0;
      result2[j][k] = result1_t_0 / temp_0 - (2.f * data2[j][k] - 1.f) / sqrtf(temp_0);
    }
  }
}
//void compute3(float result2[32][16], float data[32][784], float gradient[784+1][16])

void compute3(float result2[32][16],float data[32][784],float gradient[16][784],float gradient_2[16])
{
  int i;
  int j;
  int k;
  for (j = 0; j < 32; j++) {
    for (i = 0; i < 784; i++) {
      for (k = 0; k < 16; k++) 
/* Original: #pragma ACCEL parallel */
{
        
#pragma ACCEL PARALLEL COMPLETE
        gradient[k][i] += result2[j][k] * data[j][i];
      }
    }
  }
  for (j = 0; j < 32; j++) {
    for (k = 0; k < 16; k++) 
/* Original: #pragma ACCEL parallel */
{
      
#pragma ACCEL PARALLEL COMPLETE
      gradient_2[k] += result2[j][k];
    }
  }
}
//void pipeline( int n_samples, float *global_data, float *global_data2, float weights[784+1][16], float gradient[784+1][16] )
//void pipeline( int n_samples, float *global_data, float *global_data2, float * global_weights, float * global_gradient )
//{
//    int i;
//    int n_stage;
//    //n_stage = n_samples / 32;
//    //for(i = 0; i < n_stage; i++ )
//    for(i = 0; i < n_samples / 32; i++ )
//    {
//        float data[32][784];
//        float data2[32][16];
//        float result1[32][16];
//        float result2[32][16];
//
//        //recv_data( global_data, i * 32 * 784, data );
//        //recv_data2( global_data2, i * 32 * 16, data2 );
//        memcpy( *data, (void*)(global_data + i * 32 * 784), 784*32*4 );
//        memcpy( *data2, (void*)(global_data2 + i * 32 * 16), 16*32*4 );
//        //int __i_fcs_2;
//        //for (__i_fcs_2 = 0; __i_fcs_2 < ((size_t )(784 * 32 * 4)) / 4 - 1; ++__i_fcs_2) {
//        //  data[(__i_fcs_2 + 0) / 784][(__i_fcs_2 + 0) % 784] = global_data[__i_fcs_2 + i * 32 * 784];
//        //}
//        //int __i_fcs_3;
//        //for (__i_fcs_3 = 0; __i_fcs_3 < ((size_t )(16 * 32 * 4)) / 4 - 1; ++__i_fcs_3) {
//        //  data2[(__i_fcs_3 + 0) / 16][(__i_fcs_3 + 0) % 16] = global_data2[__i_fcs_3 + i * 32 * 16];
//        //}
//        compute1( data, global_weights, result1 );
//        compute2( result1, data2, result2 );
//        compute3( result2, data, global_gradient );
//    }
//}
#pragma ACCEL kernel
void logistic_regression_kernel(int n_samples,float *global_weights,float *global_weights_2,float *global_data,float *global_data2,float *global_gradient,float *global_gradient_2)
{
  float gradient_2_rn_rf8[16];
  float gradient_rn_rf7[16][784];
  float result2_0_rf6[32][16];
  float result1_0_rn_rf5[32][16];
  float result1_0_rf4[32][16];
  float global_weights_2_buf_0_0_rf3[16];
  float global_weights_buf_0_0_rf2[16][784];
  float gradient_2_rf1[16];
  float gradient_rf0[16][784];
  float result2_0_tmp;
  float result2_0_rn[32][16];
  float result1_0_rn[32][16];
  float data_0_tmp;
  float data_0_rn[32][784];
  float gradient_2_rn[16];
  float gradient_rn[16][784];
  int _memcpy_i4_1;
  int _memcpy_i4_0;
  int _memcpy_i3_1;
  int _memcpy_i3_0;
  int _memcpy_i2_1;
  int _memcpy_i2_0;
  int _memcpy_i0_1;
  int _memcpy_i0_0;
  float global_gradient_buf_0[784][16];
  float gradient[16][784];
  float gradient_2[16];
  int i;
  int j;
  int k;
  float data_0[32][784];
  float data2_0[32][16];
  float result1_0[32][16];
  float result2_0[32][16];
  float global_weights_buf_0_0[16][784];
  float global_weights_2_buf_0_0[16];
  int __memcpy_i_1_0;
  int i__compute1_0;
  int j__compute1_0;
  int k__compute1_0;
  int j__compute2_0;
  int k__compute2_0;
  float result1_t_0__compute2_0;
  float temp_0__compute2_0;
  int i__compute3_0;
  int j__compute3_0;
  int k__compute3_0;
  for (j = 0; j < 784; j++) {
    for (i = 0; i < 16; i++) 
/* Original: #pragma ACCEL parallel */
{
      
#pragma ACCEL PARALLEL COMPLETE
      gradient[i][j] = 0.f;
    }
  }
  for (i = 0; i < 16; i++) 
/* Original: #pragma ACCEL parallel */
{
    
#pragma ACCEL PARALLEL COMPLETE
    gradient_2[i] = 0.f;
  }
//for(i=0; i < 16; i++)
//{
//    int j;
//    for(j = 0; j < 784+1; j++) {
//        weights[j][i] = global_weights[i*784+j];
//    }
//}
//pipeline( n_samples, global_data, global_data2, weights, gradient);
//pipeline( n_samples, global_data, global_data2, global_weights, global_gradient);
  for (i = 0; i < n_samples / 32; i++) {
      for (_memcpy_i0_0 = 0; _memcpy_i0_0 < 784; ++_memcpy_i0_0) {
    for (_memcpy_i0_1 = 0; _memcpy_i0_1 < 16; ++_memcpy_i0_1) {
#pragma ACCEL PARALLEL COMPLETE
        global_weights_buf_0_0[_memcpy_i0_1][_memcpy_i0_0] = global_weights[0 + ((0 * 784 + _memcpy_i0_1) * 16 + _memcpy_i0_0)];
      }
    }
    for (__memcpy_i_1_0 = 0; __memcpy_i_1_0 < sizeof(float ) * ((unsigned long )16) / 4; ++__memcpy_i_1_0) {
#pragma ACCEL PARALLEL COMPLETE
      global_weights_2_buf_0_0[__memcpy_i_1_0 + 0] = global_weights_2[__memcpy_i_1_0 + 0];
    }
    for (_memcpy_i2_1 = 0; _memcpy_i2_1 < 32; ++_memcpy_i2_1) {
      for (_memcpy_i2_0 = 0; _memcpy_i2_0 < 784; ++_memcpy_i2_0) {
        data_0_tmp = global_data[i * 32 * 784 + ((0 * 784 + _memcpy_i2_1) * 32 + _memcpy_i2_0)];
        data_0[_memcpy_i2_1][_memcpy_i2_0] = data_0_tmp;
        data_0_rn[_memcpy_i2_1][_memcpy_i2_0] = data_0_tmp;
      }
    }
    for (_memcpy_i3_1 = 0; _memcpy_i3_1 < 32; ++_memcpy_i3_1) {
      for (_memcpy_i3_0 = 0; _memcpy_i3_0 < 16; ++_memcpy_i3_0) {
#pragma ACCEL PARALLEL COMPLETE
        data2_0[_memcpy_i3_1][_memcpy_i3_0] = global_data2[i * 32 * 16 + ((0 * 16 + _memcpy_i3_1) * 32 + _memcpy_i3_0)];
      }
    }
{
      for (j__compute1_0 = 0; j__compute1_0 < 32; j__compute1_0++) {
        for (k__compute1_0 = 0; k__compute1_0 < 16; k__compute1_0++) 
/* Original: #pragma ACCEL parallel */
{
          if (j__compute1_0 == 0) {
            global_weights_2_buf_0_0_rf3[k__compute1_0] = global_weights_2_buf_0_0[k__compute1_0];
          }
          
#pragma ACCEL PARALLEL COMPLETE
          result1_0[j__compute1_0][k__compute1_0] = global_weights_2_buf_0_0_rf3[k__compute1_0];
        }
      }
      for (i__compute1_0 = 0; i__compute1_0 < 784; i__compute1_0++) {
        for (j__compute1_0 = 0; j__compute1_0 < 32; j__compute1_0++) {
          for (k__compute1_0 = 0; k__compute1_0 < 16; k__compute1_0++) 
/* Original: #pragma ACCEL parallel */
{
            if (i__compute1_0 == 0) {
              result1_0_rf4[j__compute1_0][k__compute1_0] = result1_0[j__compute1_0][k__compute1_0];
            }
            if (j__compute1_0 == 0) {
              global_weights_buf_0_0_rf2[k__compute1_0][i__compute1_0] = global_weights_buf_0_0[k__compute1_0][i__compute1_0];
            }
            
#pragma ACCEL PARALLEL COMPLETE
//result1[j][k] += weights[i+1][k] * data[j][i];
            result1_0_rf4[j__compute1_0][k__compute1_0] += global_weights_buf_0_0_rf2[k__compute1_0][i__compute1_0] * data_0[j__compute1_0][i__compute1_0];
            result1_0_rn_rf5[j__compute1_0][k__compute1_0] = result1_0_rf4[j__compute1_0][k__compute1_0];
            if (i__compute1_0 == 783) {
              result1_0_rn[j__compute1_0][k__compute1_0] = result1_0_rn_rf5[j__compute1_0][k__compute1_0];
            }
          }
        }
      }
    }
{
      for (j__compute2_0 = 0; j__compute2_0 < 32; j__compute2_0++) {
        for (k__compute2_0 = 0; k__compute2_0 < 16; k__compute2_0++) 
/* Original: #pragma ACCEL parallel */
{
          
#pragma ACCEL PARALLEL COMPLETE
          result1_t_0__compute2_0 = result1_0_rn[j__compute2_0][k__compute2_0];
          temp_0__compute2_0 = ((float )1) + result1_t_0__compute2_0 * result1_t_0__compute2_0;
          result2_0_tmp = result1_t_0__compute2_0 / temp_0__compute2_0 - (2.f * data2_0[j__compute2_0][k__compute2_0] - 1.f) / sqrtf(temp_0__compute2_0);
          result2_0[j__compute2_0][k__compute2_0] = result2_0_tmp;
          result2_0_rn[j__compute2_0][k__compute2_0] = result2_0_tmp;
        }
      }
    }
{
      for (j__compute3_0 = 0; j__compute3_0 < 32; j__compute3_0++) {
        for (i__compute3_0 = 0; i__compute3_0 < 784; i__compute3_0++) {
          for (k__compute3_0 = 0; k__compute3_0 < 16; k__compute3_0++) 
/* Original: #pragma ACCEL parallel */
{
            if (i__compute3_0 == 0) {
              result2_0_rf6[j__compute3_0][k__compute3_0] = result2_0[j__compute3_0][k__compute3_0];
            }
            if (i == 0 && j__compute3_0 == 0) {
              gradient_rf0[k__compute3_0][i__compute3_0] = gradient[k__compute3_0][i__compute3_0];
            }
            
#pragma ACCEL PARALLEL COMPLETE
            gradient_rf0[k__compute3_0][i__compute3_0] += result2_0_rf6[j__compute3_0][k__compute3_0] * data_0_rn[j__compute3_0][i__compute3_0];
            gradient_rn_rf7[k__compute3_0][i__compute3_0] = gradient_rf0[k__compute3_0][i__compute3_0];
            if (i == - 1 + n_samples / 32 && j__compute3_0 == 31) {
              gradient_rn[k__compute3_0][i__compute3_0] = gradient_rn_rf7[k__compute3_0][i__compute3_0];
            }
          }
        }
      }
      for (j__compute3_0 = 0; j__compute3_0 < 32; j__compute3_0++) {
        for (k__compute3_0 = 0; k__compute3_0 < 16; k__compute3_0++) 
/* Original: #pragma ACCEL parallel */
{
          if (i == 0 && j__compute3_0 == 0) {
            gradient_2_rf1[k__compute3_0] = gradient_2[k__compute3_0];
          }
          
#pragma ACCEL PARALLEL COMPLETE
          gradient_2_rf1[k__compute3_0] += result2_0_rn[j__compute3_0][k__compute3_0];
          gradient_2_rn_rf8[k__compute3_0] = gradient_2_rf1[k__compute3_0];
          if (i == - 1 + n_samples / 32 && j__compute3_0 == 31) {
            gradient_2_rn[k__compute3_0] = gradient_2_rn_rf8[k__compute3_0];
          }
        }
      }
    }
  }
  for (j = 0; j < 784; j++) {
    for (i = 0; i < 16; i++) 
/* Original: #pragma ACCEL parallel */
{
      
#pragma ACCEL PARALLEL COMPLETE
      global_gradient_buf_0[j][i] = gradient_rn[i][j];
    }
  }
  for (i = 0; i < 16; i++) 
/* Original: #pragma ACCEL parallel */
{
    
#pragma ACCEL PARALLEL COMPLETE
    global_gradient_2[i] = gradient_2_rn[i];
  }
  for (_memcpy_i4_1 = 0; _memcpy_i4_1 < 784; ++_memcpy_i4_1) {
    for (_memcpy_i4_0 = 0; _memcpy_i4_0 < 16; ++_memcpy_i4_0) {
#pragma ACCEL PARALLEL COMPLETE
      global_gradient[0 + ((0 * 16 + _memcpy_i4_1) * 784 + _memcpy_i4_0)] = global_gradient_buf_0[_memcpy_i4_1][_memcpy_i4_0];
    }
  }
}
