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

#define VEC_SIZE 10000
#define VEC_DIM_SIZE 100

#pragma ACCEL kernel
void func_top_2(int *a, int *b, int *c)
{
  int j, j_sub;
  int k;

  int sum = 0;
  int sum1 = 0;
  for (j = 0; j < 1000; j++) 
  {
    for (j_sub = 0; j_sub < 10; ++j_sub) 
    {
#pragma ACCEL pipeline
      sum += a[j * 10 + j_sub];
      sum1 += a[j * 10 + j_sub];
    }
  }
  for (j_sub = 0; j_sub < 10; ++j_sub) 
#pragma ACCEL pipeline
    sum += b[j_sub];

  for (j = 0; j < 1000; j++) {
#pragma ACCEL pipeline
  for (j_sub = 0; j_sub < 10; j_sub += a[j_sub]) {
#pragma ACCEL parallel
    b[j_sub] = j_sub;
  }
  }
}

#pragma ACCEL kernel
void func_top_3(int *a, int *b, int *c)
{
	int j, j_sub;

	int sum = 0;
	int sum1 = 0;
	for (j = 0; j < 1000; j++) 
	{
		for (j_sub = 0; j_sub < 10; ++j_sub) 
		{
#pragma ACCEL pipeline
			sum += a[j * 10 + j_sub];
			sum1 += sum;
		}
	}
}

#pragma ACCEL kernel
void func_top_4(int *a)
{
	int j, j_sub;
  int sum;
	int sum1 = 0;
	for (j = 0; j < 1000; j++) 
	{
#pragma ACCEL pipeline
		for (j_sub = 0; j_sub < 10; ++j_sub) 
		{
#pragma ACCEL parallel
			sum -= a[j * 10 + j_sub];
			sum1 *= a[j * 10 + j_sub];
		}
	}
	for (j = 0; j < 1000; j++) 
	{
#pragma ACCEL pipeline
		for (sum=0, j_sub = 0; j_sub < 10; ++j_sub) 
		{
#pragma ACCEL parallel
			sum -= a[j * 10 + j_sub];
			sum1 *= a[j * 10 + j_sub];
		}
	}

}

