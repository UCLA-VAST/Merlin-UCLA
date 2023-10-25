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
#include<ap_int.h>
struct st {
  ap_int<11> a;
  int b;
  st(const st &other) {
    a = other.a;
    b = other.b;
  }
  st() {}
};
#pragma ACCEL kernel name = "vec_add_kernel"
void vec_add_kernel() { 
  struct st *a;
  for (int i = 0; i < 100; ++i) {
    struct st tmp;
    tmp.a = i;
    tmp.b = -i;
    a[i] = tmp;
  }
}

