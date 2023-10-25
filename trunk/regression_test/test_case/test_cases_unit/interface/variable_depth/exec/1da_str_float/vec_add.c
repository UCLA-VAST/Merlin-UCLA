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
#include<stddef.h>
#include "stdio.h"
#include "malloc.h"
#define VEC_SIZE 10000
void __merlinoldkernel_test_kernel(int burst_length,int burst_number,int a[1000]);
#include "__merlinhead_kernel_top.h"

int main(int argc,char **argv)
{
  int i;
  int j;
  int burst_length;
  if (argc >= 2) {
    burst_length = atoi(argv[1]);
  }
   else {
    burst_length = 1000;
  }
  int burst_number;
  if (argc >= 2) {
    burst_number = atoi(argv[2]);
  }
   else {
    burst_number = 10;
  }
  printf("\nburst_length = %d, burst_number = %d\n",burst_length,burst_number);
  //int *a = (int *)(malloc(((size_t )4LL) * burst_length));
  int a[1000];
  for (i = 0; i < burst_length; i++) {
    a[i] = i;
  }
/* Original: #pragma ACCEL task */
  
#pragma ACCEL string opencl_init("kernel_top.aocx");
  __merlinwrapper_test_kernel(burst_length,burst_number,a);
  int err = 0;
  for (i = 0; i < burst_number; i++) {
    for (j = 0; j < burst_length; j++) {
      if (i == burst_length - 1 && a[j] != i + j) {
        printf("Test failed\n");
        err = 1;
        break; 
      }
    }
  }
  if (0 == err) {
    printf("Success! %d\n",err);
    char file_name_s[256] = "pass.o";
    FILE *fp_s = fopen(file_name_s,"ab+");
    if (fp_s == ((void *)0)) {
      printf("can't create file!");
    }
  }
   else {
    printf("Fail! %d\n",err);
    char file_name[256] = "fail.o";
    FILE *fp = fopen(file_name,"ab+");
    if (fp == ((void *)0)) {
      printf("can't create file!");
    }
  }
  return 0;
}
