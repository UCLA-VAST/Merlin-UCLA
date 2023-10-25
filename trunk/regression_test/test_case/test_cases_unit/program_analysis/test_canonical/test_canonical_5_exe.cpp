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
// Testing types of iterators
#include <stdio.h>
int iig;

#pragma ACCEL kernel
void func_loop() {
  int a[1025];
  int b[1025];
  int c[1025];

  for(int pp=0; pp<1025; pp++) {
    a[pp]=1;
    b[pp]=5;
    c[pp]=2;
  }

  short is;
  int jj;
  int j = 0;
  int x, y, z;
  int N = 100;

  for (is = 0, jj = 0; is < 8; is++) {
    /* block 1*/
    c[jj] = a[is] + b[is];
    printf("index1 = %d\n", is);
  }

  for (is = 0, jj = 0; is <= 1024; is += 2) {
    /* block 2*/
    c[jj] = a[is] + b[is];
    printf("index2 = %d\n", is);
  }

  for (short ii = 0, jj = 0; ii <= N; ii++) {
    /* block 3*/
    c[jj] = a[ii] + b[ii];
    printf("index3 = %d\n", ii);
  }

  for (iig = 0, jj = 0; iig <= N; iig += 2) {
    /* block 4*/
    c[jj] = a[iig] + b[iig];
    printf("index4 = %d\n", iig);
  }

  char ii0, jj0;
  for (ii0 = 0, jj0 = 0; ii0 <= N; ii0 += 2) {
    /* block 5*/
    c[jj0] = a[ii0] + b[ii0];
    printf("index5 = %d\n", ii0);
  }
  for (ii0 = 0; ii0 <= N; ii0++) {
    /*block 6*/
    c[ii0] = a[ii0] + b[ii0];
    printf("index6 = %d\n", ii0);
  }

  for (char ii = 0, jj = 0; ii <= N; ii += 2) {
    /*block 8*/
    c[jj] = a[ii] + b[ii];
    printf("index7 = %d\n", ii);
  }

  {
    char ii, jj;
    for (ii = 0, jj = 0; ii <= N; ii += 2) {
      /*block 8.1*/
      c[jj] = a[ii] + b[ii];
      printf("index8 = %d\n", ii);
    }
  }

  for (unsigned char ii = 0; ii < 254; ii += 2) {
    /*block 9*/
    c[ii] = a[ii] + b[ii];
    printf("index9 = %d\n", ii);
  }

  for (char ii = -20; ii < 100; ii += 2) {
    /*block 9.1*/
    c[ii+21] = a[ii+21] + b[ii+21];
    printf("index9.1 = %d\n", ii+21);
  }

  for (char i = 0; 100 > i; i++) {
    for (char j = 3; j <= i; j++) {
      /*block 10*/
      c[i] = a[i] + b[j];
      printf("index10 = %d\n", i);
    }
  }


  for (unsigned long i_top = (unsigned long )0; i_top < ((unsigned long )1024L); i_top += ((unsigned long )64)) {
    for (int i_sub = 0; i_sub < 64; i_sub++) {
      /*block 12*/
      int i = (int )(i_top + ((unsigned long )i_sub));
      c[i] += a[i] + b[i];
      printf("index11 = %d\n", i);
    }
  }
  for (unsigned int ii = 0; ii <= 1024; ii += 2) {
    /*block 13*/
    c[ii] += a[ii] + b[ii];
    printf("index12 = %d\n", ii);
  }

  for (unsigned short ii = 0; ii <= 100; ii += 2) {
    /*block 13*/
    c[ii] += a[ii] + b[ii];
  }
#if 0
  for (unsigned long long ii = 0; ii <= 1024; ii += 2) {
    /*block 13*/
    c[ii] += a[ii] + b[ii];
  }
#endif

  for(int pp=0; pp<1025; pp++)
    printf("result = %d\n", c[pp]);

}

int main() {

  func_loop();
  return 0;
}
