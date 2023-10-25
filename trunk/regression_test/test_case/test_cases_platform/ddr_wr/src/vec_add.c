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

void test_kernel(int burst_length, int burst_number, int * a);

int main(int argc, char** argv)
{   
    int i, j;
    int burst_length;
    if(argc >= 2) {
      burst_length = atoi(argv[1]);
    } else {
      burst_length = 1000;
    }
    int burst_number;
    if(argc >= 2) {
      burst_number = atoi(argv[2]);
    } else {
      burst_number = 10;
    }
    printf("\nburst_length = %d, burst_number = %d\n", burst_length, burst_number);
    int * a = (int*)malloc(sizeof(int) * burst_length);
    for(i = 0; i < burst_length; i++) {
        a[i] = i;
    }

#pragma ACCEL task name="vec_add"
    test_kernel(burst_length, burst_number, a);

    return 0;
}


