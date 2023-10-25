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
void sub_func (int a[100]) {
    for (int j = 0; j < 100; j++)
    {
#pragma ACCEL pipeline
        a[j] = 0;
    }
}
#pragma ACCEL kernel
void func_top_1() {
  int b[100][100];
  int t=10;
  int i;
  int j;
  int aa[100];
  int ab[100];
  sub_func(ab);
  for (i = 0; i < 100; i++)
  {
    for (j = 0; j < 100; j++)
    {
#pragma ACCEL pipeline
        aa[j] = b[i][j] + ab[j] + ab[j+1] + ab[j+2];
    }
  }

  for (i = 0; i < 100; i++)
  {
    int a[100][100];
    for (j = 0; j < 100; j++)
    {
      while(t > 0) {
#pragma ACCEL pipeline
        a[i][j] = b[i][j] + (t--);
      }
    }
  }
}

#pragma ACCEL kernel
void func_top_2() {
  float C[16][224][224];
#pragma HLS array_partition variable=C cyclic factor=2 dim=3
#pragma HLS array_partition variable=C cyclic factor=2 dim=2
#pragma HLS array_partition variable=C complete dim=1

  for (int j = 0; j < 256; ++j) {
    float merlin_input_buf[228][228];
#pragma HLS array_partition variable=merlin_input_buf cyclic factor = 4 dim=2
loop_h:
    for (int h = 0; h < 224; ++h) {
loop_w:
      for (int w = 0; w < 224; ++w) {
#pragma ACCEL PIPELINE AUTO
loop_p:
        for (int iter = 0; iter < 16; iter++) {
#pragma ACCEL PARALLEL COMPLETE
          float tmp = (float )0;
          for (int p = 0; p < 5; ++p) {
#pragma ACCEL PARALLEL COMPLETE
Loop_q:
            for (int q = 0; q < 5; ++q) {
#pragma ACCEL PARALLEL COMPLETE
              tmp += merlin_input_buf[h + p][q + w];
            }
          }
          C[iter][h][w] += tmp;
        }
      }
    }
  }
}
