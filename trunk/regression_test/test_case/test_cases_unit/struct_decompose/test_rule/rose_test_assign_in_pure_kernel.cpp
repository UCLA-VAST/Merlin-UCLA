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
#include<hls_stream.h>
#include<stdlib.h>
#define N 100

struct st 
{
  int a;
  char b[4];
}
;
#pragma ACCEL kernel

void top(class hls::stream< st  > &in_data,class hls::stream< st  > &out_data)
{
  int i_2_0;
  struct st tmp;
  tmp = in_data . read();
  struct st tmp2;
  tmp2 . a = tmp . a;
  for (i_2_0 = 0; i_2_0 < 4UL; ++i_2_0) {
    tmp2 . b[i_2_0] = tmp . b[i_2_0];
  }
  out_data . write(tmp2);
}
