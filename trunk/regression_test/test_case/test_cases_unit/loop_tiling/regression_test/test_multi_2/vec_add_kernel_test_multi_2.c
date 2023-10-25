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

void f1() {
  int i, x;

  for (i = 0; i < 10250; ++i) {
#pragma ACCEL tile faCTor = 4
#pragma ACCEL tile factor = 8
#pragma ACCEL tile factor = 2
    x = x + i;
  }
}

void f2() {
  int i, x;

  for (i = 0; i < 10250; ++i) {
#pragma ACCEL pipeline
#pragma ACCEL tile faCTor = 4
#pragma ACCEL tile factor = 8
#pragma ACCEL tile factor = 2
    x = x + i;
  }
}

void f3() {
  int i, x;

  for (i = 0; i < 10250; ++i) {
#pragma ACCEL tile faCTor = 4
#pragma ACCEL pipeline
#pragma ACCEL tile factor = 8
#pragma ACCEL tile factor = 2
    x = x + i;
  }
}

void f4() {
  int i, x;

  for (i = 0; i < 10250; ++i) {
#pragma ACCEL tile faCTor = 4
#pragma ACCEL tile factor = 8
#pragma ACCEL tile factor = 2
#pragma ACCEL pipeline
    x = x + i;
  }
}

void f5() {
  int i, x;

  for (i = 0; i < 10250; ++i) {
#pragma ACCEL parallel faCTor = 4
#pragma ACCEL tile factor = 8
#pragma ACCEL tile factor = 2
    x = x + i;
  }
}

void f6() {
  int i, x;

  for (i = 0; i < 10250; ++i) {
#pragma ACCEL tile faCTor = 4
#pragma ACCEL parallel factor = 8
#pragma ACCEL tile factor = 2
    x = x + i;
  }
}

void f7() {
  int i, x;

  for (i = 0; i < 10250; ++i) {
#pragma ACCEL tile faCTor = 4
#pragma ACCEL tile factor = 8
#pragma ACCEL parallel factor = 2
    x = x + i;
  }
}

void f8() {
  int i, x;

  for (i = 0; i < 10250; ++i) {
#pragma ACCEL parallel faCTor = 4
#pragma ACCEL tile factor = 8
#pragma ACCEL tile factor = 2
#pragma ACCEL pipeline
    x = x + i;
  }
}

void f9() {
  int i, x;

  for (i = 0; i < 10250; ++i) {
#pragma ACCEL tile faCTor = 4
#pragma ACCEL parallel factor = 8
#pragma ACCEL pipeline
#pragma ACCEL tile factor = 2
    x = x + i;
  }
}

void f10() {
  int i, x;

  for (i = 0; i < 10250; ++i) {
#pragma ACCEL tile faCTor = 4
#pragma ACCEL tile factor = 8
#pragma ACCEL pipeline
#pragma ACCEL parallel factor = 2
    x = x + i;
  }
}

void f11() {
  int i, x;

  for (i = 0; i < 63; ++i) {
#pragma ACCEL tile faCTor = 4
#pragma ACCEL tile factor = 8
#pragma ACCEL pipeline
#pragma ACCEL parallel factor = 2
    x = x + i;
  }
}

#pragma ACCEL kernel
void vec_add_kernel(int *a, int *b, int*c, int inc, int n)
{
  f1();
  f2();
  f3();
  f4();
  f5();
  f6();
  f7();
  f8();
  f9();
  f10();
  f11();
}
