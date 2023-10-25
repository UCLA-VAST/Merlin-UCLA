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

#define IMG_OUT_NUM 8
#define IMG_IN_NUM 8
#define IMG_ROW 8
#define IMG_COL 8
#define KERNEL 3


void compute_gold(float* out, const float* in, const float* weight) {

#pragma ACCEL systolic auto=auto
	for (int o = 0; o < IMG_OUT_NUM; o++)
	for (int i = 0; i < IMG_IN_NUM; i++)
	for (int r = 0; r < IMG_ROW; r++)
	for (int c = 0; c < IMG_COL; c++)
	for (int p = 0; p < KERNEL; p++)
	for (int q = 0; q < KERNEL; q++) {
			out[o * (IMG_ROW * IMG_COL) + r * IMG_COL + c] += 
					weight[o * (IMG_OUT_NUM * KERNEL * KERNEL) + i * (KERNEL * KERNEL) + p * KERNEL + q] * 
					in[i * (IMG_ROW * IMG_COL) + (r + p) * IMG_COL + (c + q)];
	}

	return ;
}

