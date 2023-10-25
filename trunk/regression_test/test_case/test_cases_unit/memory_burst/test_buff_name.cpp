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
int b_buf[10];
#pragma ACCEL kernel
void top(int *a, int *b) {
  for (int i = 0; i < 100; ++i) {
    int a_buf[4];
    for (int j = 0; j < 4; ++j) {
      a_buf[j] = a[i * 100 +j] + 1;
    }
    b[i] = a_buf[0] + a_buf[3] + b_buf[2];
  }
}

