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
#include<string.h>

#pragma ACCEL kernel
void func1_kernel(int *a, int *b) {
#pragma ACCEL interface variable=a depth=1024
#pragma ACCEL interface variable=b depth=1024
    int a_buf[1024];
    int b_buf[1024];
    memcpy(a_buf, a, sizeof(int) * 1024);
    for (int i = 0; i < 1024; ++i) {
        b_buf[i] = a_buf[i];
    }
    memcpy(b, b_buf, sizeof(int) * 1024);
}

int main() {
    int a[1024] = {0}, b[1024];
    func1_kernel(a, b);
    return 0;
}
