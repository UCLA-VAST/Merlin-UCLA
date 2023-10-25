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
static float x;

void simple_float() {
  int i;

  for (i = 0, (x *= 8); i < 100; ++i) {
#pragma ACCEL pipeline
  }
  for (i = 0; i < 100 && (x *= 8); ++i) {
#pragma ACCEL pipeline
  }
  for (i = 0; i < 100; ++i, (x *= 8)) {
#pragma ACCEL pipeline
  }
  for (i = 0; i < 100; ++i) {
#pragma ACCEL pipeline
    (x *= 8);
  }
  while (1) {
#pragma ACCEL pipeline
    x *= 8;
  }
  while (x *= 8) {
#pragma ACCEL pipeline
  }
}

static double xx;

void simple_double() {
  int i;

  for (i = 0, (xx *= 8); i < 100; ++i) {
#pragma ACCEL pipeline
  }
  for (i = 0; i < 100 && (xx *= 8); ++i) {
#pragma ACCEL pipeline
  }
  for (i = 0; i < 100; ++i, (xx *= 8)) {
#pragma ACCEL pipeline
  }
  for (i = 0; i < 100; ++i) {
#pragma ACCEL pipeline
    (xx *= 8);
  }
  while (1) {
#pragma ACCEL pipeline
    xx *= 8;
  }
  while (xx *= 8) {
#pragma ACCEL pipeline
  }
}

double f(double x, double y) {
  return x + y;
}

void complicated() {
  int i;
  double y, z;

  for (i = 0, (xx *= y + z + f(y, z)); i < 100; ++i) {
#pragma ACCEL pipeline
  }
  for (i = 0; i < 100 && (xx *= y + z + f(y, z)); ++i) {
#pragma ACCEL pipeline
  }
  for (i = 0; i < 100; ++i, (xx *= y + z + f(y, z))) {
#pragma ACCEL pipeline
  }
  for (i = 0; i < 100; ++i) {
#pragma ACCEL pipeline
    (xx *= y + z + f(y, z));
  }
  while (1) {
#pragma ACCEL pipeline
    xx *= y + z + f(y, z);
  }
  while (xx *= y + z + f(y, z)) {
#pragma ACCEL pipeline
  }
}

#pragma ACCEL kernel
void g() {
  float &fff = x;
  double *ddd = &xx;
  simple_float();
  simple_double();
  complicated();
}
