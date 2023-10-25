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
#include<string.h>
#pragma accel kernel
void top(int *a, int *b) {
#pragma ACCEL interface variable=a depth=10
#pragma ACCEL interface variable=b depth=1
  int i, j, index;
  int a_buf[10];
  memcpy(a_buf, a, sizeof(int) * 10);
  for (i = 0; i < 10; ++i)  {
#pragma ACCEL parallel
    for (j = 0; j < 10; ++j) {
      if (a_buf[j] > 0) {
        index = j;
      }
    }
  }
  b[0] = index;
  return;
}
