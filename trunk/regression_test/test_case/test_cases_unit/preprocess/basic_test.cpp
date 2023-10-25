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
struct A {
  int a;
};

#pragma ACCEL kernel
void top_with_aggr_class_array(int *a) {
  A c_a[10] = {0};
  a[0] = c_a[0].a;
}

// 1. loop structure
// 2. function structure
// 3. access pattern
// 4. pragma modes
#pragma ACCEL kernel
void func_top_0(int * a, int * b)
{
    int i;
    int j;
    bool a_buf[100];
#pragma ACCEL pipeline flatten
    for (j = 0; j < 100; ++j) {
        for (i = 0; i < 100; i++)
        {
            a_buf[i]+= b[i];
        }
    }
}

