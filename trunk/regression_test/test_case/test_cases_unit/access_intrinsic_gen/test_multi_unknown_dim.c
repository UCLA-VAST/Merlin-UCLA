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
void sub(int *a) {}
#pragma ACCEL kernel
void top(int a[100], int *b) {
#pragma ACCEL interface variable=b depth=100
  sub(a);
  sub(b);
}
void sub_1_1(int *a) {};
void sub_1(int *a) { sub_1_1(a);}
#pragma ACCEL kernel
void top_1(int a[100], int *b) {
#pragma ACCEL interface variable=b depth=10
  sub_1(a);
  sub_1_1(b);
}

void sub_2(int a[10]) {}
#pragma ACCEL kernel
void top_2(int a[100], int *b) {
  sub_2(a);
  sub_2(b);
}

void sub_3(int *a) {}
#pragma ACCEL kernel
void top_3(int a[100], int *b) {
  sub_3(a);
  sub_3(b);
}


