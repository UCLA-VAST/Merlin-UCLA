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
/* (previously processed: ignoring self-referential macro declaration) macro name = c */ 
#pragma ACCEL kernel

void func_top_3(int c[32][32][32])
{

#pragma ACCEL interface variable=c max_depth=32,32,32 depth=32,32,32 BURST_OFF
  int sum;
  for (int i = 0; i < 31; i++) {
    int LineBuffer_c0[30];
    int slide_wind_0[2][3];
    for (int j = -1L; j < 31; j++) {
      for (int k = 0L; k < 30; k++) {

#pragma ACCEL pipeline
        {
          int j_2;
          int j_1;
          int tmp_wind_0[2];
          int k_0;
          int j_0;
          for (j_0 = 0L; j_0 <= 1L; ++j_0) {

#pragma ACCEL PARALLEL COMPLETE
            for (k_0 = 1L; k_0 <= 2L; ++k_0) {

#pragma ACCEL PARALLEL COMPLETE
              slide_wind_0[j_0][k_0 + -1] = slide_wind_0[j_0][k_0];
            }
          }
          for (j_1 = 0; j_1 <= 1L; ++j_1) {

#pragma ACCEL PARALLEL COMPLETE
            if (j_1 == 0L) {
              tmp_wind_0[j_1] = LineBuffer_c0[k - 2L + 2L];
            }
          }
          tmp_wind_0[1UL] = c[1L + i * 1L][j + 0L + 1L][k + 0L + 2L];
          for (j_2 = 0; j_2 <= 1L; ++j_2) {

#pragma ACCEL PARALLEL COMPLETE
            slide_wind_0[j_2][2L] = tmp_wind_0[j_2];
          }
          {
            int j_3;
            int tmp_c;
            for (j_3 = 0; j_3 <= 0UL; ++j_3) {

#pragma ACCEL PARALLEL COMPLETE
              tmp_c = tmp_wind_0[j_3 + 1];
              if (j_3 == 0L) {
                LineBuffer_c0[k - 2L + 2L] = tmp_c;
              }
            }
          }
        }
        if (j >= 0L && j <= 30L && k >= 2L && k <= 29L) {
          sum += slide_wind_0[1L][0L] + slide_wind_0[0L][2L];
        }
      }
    }
  }
}
