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

#include<assert.h>

#define VEC_SIZE 10000


#pragma ACCEL kernel
void vec_add_kernel(int *a, int *b, int*c, int inc, int n)
{
#pragma ACCEL interface variable=a max_depth=VEC_SIZE
#pragma ACCEL interface variable=b max_depth=VEC_SIZE
#pragma ACCEL interface variable=c max_depth=VEC_SIZE
    int i, j, k, m;
#pragma ACCEL pipeline
    for (j = 0 ;j < 2; j++) 
     for (k = 0 ;k < 5; k++) 
       for (i = 0 ;i < 10; i++) 
         for (m = 0 ;m < 100; m++) {
           int index = j * 5000 + k * 1000 + i * 100 + m;
           c[index] = a[index] + b[index] + inc;
         }
}
