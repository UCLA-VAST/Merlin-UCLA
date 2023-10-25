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

struct st 
{
  int *a;
  int b;
}
;

struct st2 
{
  struct st *c;
}
;
typedef struct st st;
typedef struct st2 st2;
#pragma ACCEL kernel

void top(int ***a_c_a,int **a_c_b)
{
  
#pragma ACCEL INTERFACE DEPTH=1,2 VARIABLE=a_c_b max_depth=1,2
  
#pragma ACCEL INTERFACE DEPTH=1,2,3 VARIABLE=a_c_a max_depth=1,2,3
  a_c_b[0][0] = 0;
  a_c_a[2][0][0] = 1;
}
