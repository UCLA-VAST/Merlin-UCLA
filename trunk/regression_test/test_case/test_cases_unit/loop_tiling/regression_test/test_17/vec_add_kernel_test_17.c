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

#pragma ACCEL kernel
void vec_add_kernel(int *a, int *b, int*c, int inc)
{
    int j,k;
    int n;
    #pragma ACCEL pipeline
    #pragma ACCEL parallel factor = 3
    for  (j = 1  ;j < n; j++)
    #pragma ACCEL parallel factor = 5
        for (k = 1;k < 20; k++)
            c[j*10+k*20] = a[j*10+k*20]+b[j+k]+inc;
}
