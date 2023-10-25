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
#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include "merlin_type_define.h"
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_431();
void vec_add(int s,int a1[1024],int a2[1024],int a3[1024],int a4[1024],int a5[1024],int a6[1024],int a7[1024],int a8[1024],int a9[1024],int a10[1024],int merlin_return_value[1]);
static void __merlin_dummy_extern_int_merlin_include_L_();
#include "__merlinhead_kernel_top.h"
static void __merlin_dummy_extern_int_merlin_include_L_();

int __merlinwrapper_vec_add(int s,int a1[1024],int a2[1024],int a3[1024],int a4[1024],int a5[1024],int a6[1024],int a7[1024],int a8[1024],int a9[1024],int a10[1024])
{
  int merlin_return_value[1];
{
    
#pragma ACCEL wrapper variable=s port=s
    
#pragma ACCEL wrapper variable=a1 port=a1 depth=1024 max_depth=1024 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=a2 port=a2 depth=1024 max_depth=1024 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=a3 port=a3 depth=1024 max_depth=1024 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=a4 port=a4 depth=1024 max_depth=1024 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=a5 port=a5 depth=1024 max_depth=1024 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=a6 port=a6 depth=1024 max_depth=1024 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=a7 port=a7 depth=1024 max_depth=1024 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=a8 port=a8 depth=1024 max_depth=1024 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=a9 port=a9 depth=1024 max_depth=1024 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=a10 port=a10 depth=1024 max_depth=1024 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=merlin_return_value port=merlin_return_value depth=1 max_depth=1 data_type=int io=WO copy=true scope_type=return
  }
  static int __m_a1[1024];
  static int __m_a2[1024];
  static int __m_a3[1024];
  static int __m_a4[1024];
  static int __m_a5[1024];
  static int __m_a6[1024];
  static int __m_a7[1024];
  static int __m_a8[1024];
  static int __m_a9[1024];
  static int __m_a10[1024];
  static int __m_merlin_return_value[1];
{
/*
    static int __m_a1[1024];
    static int __m_a2[1024];
    static int __m_a3[1024];
    static int __m_a4[1024];
    static int __m_a5[1024];
    static int __m_a6[1024];
    static int __m_a7[1024];
    static int __m_a8[1024];
    static int __m_a9[1024];
    static int __m_a10[1024];
    static int __m_merlin_return_value[1];
*/
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a1", "1024 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (a1 != 0) {
        memcpy((void *)(__m_a1 + 0),(const void *)a1,1024 * sizeof(int ));
      }
       else {
        printf("Error! The external memory pointed by 'a1' is invalid.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a1");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a2", "1024 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (a2 != 0) {
        memcpy((void *)(__m_a2 + 0),(const void *)a2,1024 * sizeof(int ));
      }
       else {
        printf("Error! The external memory pointed by 'a2' is invalid.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a2");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a3", "1024 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (a3 != 0) {
        memcpy((void *)(__m_a3 + 0),(const void *)a3,1024 * sizeof(int ));
      }
       else {
        printf("Error! The external memory pointed by 'a3' is invalid.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a3");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a4", "1024 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (a4 != 0) {
        memcpy((void *)(__m_a4 + 0),(const void *)a4,1024 * sizeof(int ));
      }
       else {
        printf("Error! The external memory pointed by 'a4' is invalid.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a4");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a5", "1024 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (a5 != 0) {
        memcpy((void *)(__m_a5 + 0),(const void *)a5,1024 * sizeof(int ));
      }
       else {
        printf("Error! The external memory pointed by 'a5' is invalid.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a5");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a6", "1024 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (a6 != 0) {
        memcpy((void *)(__m_a6 + 0),(const void *)a6,1024 * sizeof(int ));
      }
       else {
        printf("Error! The external memory pointed by 'a6' is invalid.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a6");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a7", "1024 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (a7 != 0) {
        memcpy((void *)(__m_a7 + 0),(const void *)a7,1024 * sizeof(int ));
      }
       else {
        printf("Error! The external memory pointed by 'a7' is invalid.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a7");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a8", "1024 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (a8 != 0) {
        memcpy((void *)(__m_a8 + 0),(const void *)a8,1024 * sizeof(int ));
      }
       else {
        printf("Error! The external memory pointed by 'a8' is invalid.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a8");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a9", "1024 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (a9 != 0) {
        memcpy((void *)(__m_a9 + 0),(const void *)a9,1024 * sizeof(int ));
      }
       else {
        printf("Error! The external memory pointed by 'a9' is invalid.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a9");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a10", "1024 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (a10 != 0) {
        memcpy((void *)(__m_a10 + 0),(const void *)a10,1024 * sizeof(int ));
      }
       else {
        printf("Error! The external memory pointed by 'a10' is invalid.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a10");
      
#pragma ACCEL debug fflush(stdout);
    }
  }
  
#pragma ACCEL kernel
  vec_add(s,__m_a1,__m_a2,__m_a3,__m_a4,__m_a5,__m_a6,__m_a7,__m_a8,__m_a9,__m_a10,__m_merlin_return_value);
{
    int merlin_return_value[1];
/*
    static int __m_a1[1024];
    static int __m_a2[1024];
    static int __m_a3[1024];
    static int __m_a4[1024];
    static int __m_a5[1024];
    static int __m_a6[1024];
    static int __m_a7[1024];
    static int __m_a8[1024];
    static int __m_a9[1024];
    static int __m_a10[1024];
    static int __m_merlin_return_value[1];
*/
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy out", "merlin_return_value", "1 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (merlin_return_value != 0) {
        memcpy((void *)merlin_return_value,(const void *)(__m_merlin_return_value + 0),1 * sizeof(int ));
      }
       else {
        printf("Error! The external memory pointed by 'merlin_return_value' is invalid.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy out", "merlin_return_value");
      
#pragma ACCEL debug fflush(stdout);
    }
  }
  return  *merlin_return_value;
}

int __merlin_vec_add(int s,int a1[1024],int a2[1024],int a3[1024],int a4[1024],int a5[1024],int a6[1024],int a7[1024],int a8[1024],int a9[1024],int a10[1024])
{
  
#pragma ACCEL string __merlin_check_opencl();
  
#pragma ACCEL string __merlin_init_vec_add();
  __merlinwrapper_vec_add(s,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10);
  
#pragma ACCEL string __merlin_release_vec_add();
}

int __merlin_write_buffer_vec_add(int s,int a1[1024],int a2[1024],int a3[1024],int a4[1024],int a5[1024],int a6[1024],int a7[1024],int a8[1024],int a9[1024],int a10[1024])
{
  static int __m_a1[1024];
  static int __m_a2[1024];
  static int __m_a3[1024];
  static int __m_a4[1024];
  static int __m_a5[1024];
  static int __m_a6[1024];
  static int __m_a7[1024];
  static int __m_a8[1024];
  static int __m_a9[1024];
  static int __m_a10[1024];
  static int __m_merlin_return_value[1];
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a1", "1024 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (a1 != 0) {
      memcpy((void *)(__m_a1 + 0),(const void *)a1,1024 * sizeof(int ));
    }
     else {
      printf("Error! The external memory pointed by 'a1' is invalid.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a1");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a2", "1024 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (a2 != 0) {
      memcpy((void *)(__m_a2 + 0),(const void *)a2,1024 * sizeof(int ));
    }
     else {
      printf("Error! The external memory pointed by 'a2' is invalid.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a2");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a3", "1024 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (a3 != 0) {
      memcpy((void *)(__m_a3 + 0),(const void *)a3,1024 * sizeof(int ));
    }
     else {
      printf("Error! The external memory pointed by 'a3' is invalid.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a3");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a4", "1024 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (a4 != 0) {
      memcpy((void *)(__m_a4 + 0),(const void *)a4,1024 * sizeof(int ));
    }
     else {
      printf("Error! The external memory pointed by 'a4' is invalid.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a4");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a5", "1024 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (a5 != 0) {
      memcpy((void *)(__m_a5 + 0),(const void *)a5,1024 * sizeof(int ));
    }
     else {
      printf("Error! The external memory pointed by 'a5' is invalid.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a5");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a6", "1024 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (a6 != 0) {
      memcpy((void *)(__m_a6 + 0),(const void *)a6,1024 * sizeof(int ));
    }
     else {
      printf("Error! The external memory pointed by 'a6' is invalid.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a6");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a7", "1024 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (a7 != 0) {
      memcpy((void *)(__m_a7 + 0),(const void *)a7,1024 * sizeof(int ));
    }
     else {
      printf("Error! The external memory pointed by 'a7' is invalid.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a7");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a8", "1024 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (a8 != 0) {
      memcpy((void *)(__m_a8 + 0),(const void *)a8,1024 * sizeof(int ));
    }
     else {
      printf("Error! The external memory pointed by 'a8' is invalid.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a8");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a9", "1024 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (a9 != 0) {
      memcpy((void *)(__m_a9 + 0),(const void *)a9,1024 * sizeof(int ));
    }
     else {
      printf("Error! The external memory pointed by 'a9' is invalid.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a9");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a10", "1024 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (a10 != 0) {
      memcpy((void *)(__m_a10 + 0),(const void *)a10,1024 * sizeof(int ));
    }
     else {
      printf("Error! The external memory pointed by 'a10' is invalid.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a10");
    
#pragma ACCEL debug fflush(stdout);
  }
}

int __merlin_read_buffer_vec_add(int s,int a1[1024],int a2[1024],int a3[1024],int a4[1024],int a5[1024],int a6[1024],int a7[1024],int a8[1024],int a9[1024],int a10[1024])
{
  int merlin_return_value[1];
  static int __m_a1[1024];
  static int __m_a2[1024];
  static int __m_a3[1024];
  static int __m_a4[1024];
  static int __m_a5[1024];
  static int __m_a6[1024];
  static int __m_a7[1024];
  static int __m_a8[1024];
  static int __m_a9[1024];
  static int __m_a10[1024];
  static int __m_merlin_return_value[1];
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy out", "merlin_return_value", "1 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (merlin_return_value != 0) {
      memcpy((void *)merlin_return_value,(const void *)(__m_merlin_return_value + 0),1 * sizeof(int ));
    }
     else {
      printf("Error! The external memory pointed by 'merlin_return_value' is invalid.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy out", "merlin_return_value");
    
#pragma ACCEL debug fflush(stdout);
  }
  return  *merlin_return_value;
}

int __merlin_execute_vec_add(int s,int a1[1024],int a2[1024],int a3[1024],int a4[1024],int a5[1024],int a6[1024],int a7[1024],int a8[1024],int a9[1024],int a10[1024])
{
}
