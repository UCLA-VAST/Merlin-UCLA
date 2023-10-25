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
#include "stdio.h"
static void __merlin_dummy_630();
void test_kernel(int burst_length,int burst_number,int a[1000][1000]);
#include "__merlinhead_kernel_top.h"

void __merlinwrapper_test_kernel(int burst_length,int burst_number,int a[1000][1000])
{
  
#pragma ACCEL task
  test_kernel(burst_length,burst_number,a);
}
