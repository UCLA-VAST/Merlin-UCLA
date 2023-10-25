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
#include<stdlib.h>

#define N 2 

struct st {
  int a;
  char b;
};

struct st g[] = {{1, 'c'}, {2, 'd'}};

#pragma ACCEL kernel
void top(struct st *a) {
#pragma ACCEL interface variable=a depth=100
	int i;

  struct st l[] = {{1, 'c'}, {2, 'd'}};
  for (i = 0; i < N; ++i) {
    a[i].a = a[i].a + g[i].b + l[i].a;
  }
  return;
}

int main() {
	int i;
  struct st *a;
  a = (struct st*) malloc(sizeof(struct st) * N);
  for (i = 0; i < N; ++i) {
    a[i].a = i;
	g[i].b = '0';
  }
  top(a);
  return 0;

}
