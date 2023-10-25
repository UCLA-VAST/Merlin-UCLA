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
#define N 5
#define n 100
#pragma ACCEL kernel
void func_top_0(int b[100][100], int *c) {
#pragma ACCEL INTERFACE VARIABLE=c DEPTH=1000
  int tmp;
  int i;
  int j = 0;
  for (i = 0; i < 99; i++) {
    while( j < 100) {
#pragma ACCEL line_buffer variable=c
      tmp += c[i] + c[i + 1];
      j++;
    }
  }
}

