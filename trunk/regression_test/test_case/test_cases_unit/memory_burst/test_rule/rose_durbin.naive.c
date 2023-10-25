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

void kernel_durbin(int n,int yy[32][32],int sum[32][32],int sumi[32][32],int alpha[32],int beta[32],int r[32],int out[32])
{
  int i;
  int k;
  int y[32][32];
  y[0][0] = r[0];
  beta[0] = 1;
  alpha[0] = r[0];
  for (k = 1; k < 32; k++) {
    beta[k] = beta[k - 1] - alpha[k - 1] * alpha[k - 1] * beta[k - 1];
    sum[0][k] = r[k];
    for (i = 0; i <= k - 1; i++) {
      
#pragma ACCEL pipeline II=1
      sumi[i + 1][k] = sum[i][k] + r[k - i - 1] * y[i][k - 1];
    }
    alpha[k] = -sumi[k][k] * beta[k];
    for (i = 0; i <= k - 1; i = i + 2) {
      
#pragma ACCEL pipeline
      yy[i][k] = y[i][k - 1] + alpha[k] * y[k - i - 1][k - 1];
      yy[i][k + 1] = y[i][k] + alpha[k + 1] * y[k - i][k];
    }
    yy[k][k] = alpha[k];
  }
  for (i = 0; i < 32; i++) {
    out[i] = yy[i][32 - 1];
  }
}
