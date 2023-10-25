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
/****************************************************************************/
// vec_add_kernel.cpp
// Copyright (C) 2017 Xilinx, Inc. - All rights reserved.
/****************************************************************************/
#define VEC_SIZE 200000
static void __merlin_dummy_kernel_pragma();

void vec_add_kernel(int a[200000],int b[200000],int c[200000],int inc,int d[200000],long e[200000],int f[200000],int g[200000],long h[200000],long i[200000])
{
  b[0] = a[0];
  c[0] += a[0];
  d[0] = a[0];
  e[0] = a[0];
  g[0] = f[0];
  h[0] = a[0];
  h[1] = i[1];
}
