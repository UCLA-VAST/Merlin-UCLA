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
void vec_add_kernel2_merlin_clone1(int *d,int *b,int *c,int inc);
#include "__merlinhead_kernel_top.h"

void __merlinwrapper_vec_add_kernel2(int *d,int *b,int *c,int inc)
{
#pragma ACCEL kernel die=SLR1
  vec_add_kernel2_merlin_clone1(d,b,c,inc);
}

void __merlin_vec_add_kernel2(int *d,int *b,int *c,int inc)
{
  __merlinwrapper_vec_add_kernel2(d,b,c,inc);
}

void __merlin_write_buffer_vec_add_kernel2(int *d,int *b,int *c,int inc)
{
}

void __merlin_read_buffer_vec_add_kernel2(int *d,int *b,int *c,int inc)
{
}

void __merlin_execute_vec_add_kernel2(int *d,int *b,int *c,int inc)
{
}