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
static int a = 0;
static int b;
static int aa[2][2];
static int bb[2][2] = {{1, 2}, {3, 4}};
#pragma ACCEL kernel
void top(int *c) {
  c[0] = a + b + aa[0][0] + bb[1][1];
}

int main() {
  b = 5;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      aa[i][j] = i * j;
  int c[1];
  top(c);
  return c[0];
}