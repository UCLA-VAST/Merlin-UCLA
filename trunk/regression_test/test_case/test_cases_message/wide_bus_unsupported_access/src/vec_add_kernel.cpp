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
#include<assert.h>

#define VEC_SIZE 10000

void func(int *a) {
  int a_buf[200];
  memcpy(a_buf, a, sizeof(int) * 200);
  for (int i = 0; i < 200; ++i)
    a_buf[i]++;
  memcpy(a, a_buf, sizeof(int) * 200);

}

#pragma ACCEL kernel
void vec_add_kernel(int *a, int *b, int*c, int inc, int n)
{
#pragma ACCEL interface variable=a depth=n max_depth=VEC_SIZE
#pragma ACCEL interface variable=b depth=n max_depth=VEC_SIZE
#pragma ACCEL interface variable=c depth=n max_depth=VEC_SIZE
    assert(n < 1000);
    assert(n > 0);
    int j;
    int *pa = a;
    int a_buf[1000];
    memcpy(a_buf, a, sizeof(int) * n);
#pragma ACCEL pipeline
    for (j = 0 ;j < n; j++) 
      c[j] = pa[j]+b[j]+inc + a_buf[j];
    func(&b[2]);
}
