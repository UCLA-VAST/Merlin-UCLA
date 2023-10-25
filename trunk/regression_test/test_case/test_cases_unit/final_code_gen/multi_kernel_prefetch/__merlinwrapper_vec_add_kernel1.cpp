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
void vec_add_kernel1(int *a,int *b,int *c,int inc);
static void __merlin_dummy_extern_int_merlin_include_L_();
#include "__merlinhead_kernel_top.h"
static void __merlin_dummy_extern_int_merlin_include_L_();
void msm_port_a_vec_add_kernel1_0(int *a);
void msm_port_b_vec_add_kernel1_0(int *b);
void msm_port_c_vec_add_kernel1_0(int *c);

void __merlinwrapper_vec_add_kernel1(int *a,int *b,int *c,int inc)
{
{
    
#pragma ACCEL wrapper variable=a port=a depth=10000 max_depth=10000 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=b port=b depth=10000 max_depth=10000 data_type=int io=RO copy=false
    
#pragma ACCEL wrapper variable=c port=c depth=10000 max_depth=10000 data_type=int io=WO copy=false
    
#pragma ACCEL wrapper variable=inc port=inc
  }
  static int __m_a[10000];
  static int __m_b[10000];
  static int __m_c[10000];
{
/*
    static int __m_a[10000];
    static int __m_b[10000];
    static int __m_c[10000];
*/
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a", "10000 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (a != 0) {
        memcpy((void *)(__m_a + 0),(const void *)a,10000 * sizeof(int ));
      }
       else {
        printf("Error! Detected null pointer 'a' for external memory.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "b", "10000 * sizeof(int )");
      
#pragma ACCEL debug fflush(stdout);
      if (b != 0) {
        memcpy((void *)(__m_b + 0),(const void *)b,10000 * sizeof(int ));
      }
       else {
        printf("Error! Detected null pointer 'b' for external memory.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "b");
      
#pragma ACCEL debug fflush(stdout);
    }
  }
  
#pragma ACCEL sub_kernel parent=vec_add_kernel1
  msm_port_a_vec_add_kernel1_0(__m_a);
  
#pragma ACCEL sub_kernel parent=vec_add_kernel1
  msm_port_b_vec_add_kernel1_0(__m_b);
  
#pragma ACCEL kernel die=SLR0
  vec_add_kernel1(__m_a,__m_b,__m_c,inc);
  
#pragma ACCEL sub_kernel parent=vec_add_kernel1
  msm_port_c_vec_add_kernel1_0(__m_c);
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy out", "c", "10000 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (c != 0) {
      memcpy((void *)c,(const void *)(__m_c + 0),10000 * sizeof(int ));
    }
     else {
      printf("Error! Detected null pointer 'c' for external memory.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy out", "c");
    
#pragma ACCEL debug fflush(stdout);
  }
}

void __merlin_vec_add_kernel1(int *a,int *b,int *c,int inc)
{
  
#pragma ACCEL string __merlin_check_opencl();
  
#pragma ACCEL string __merlin_init_vec_add_kernel1();
  __merlinwrapper_vec_add_kernel1(a,b,c,inc);
  
#pragma ACCEL string __merlin_release_vec_add_kernel1();
}

void __merlin_write_buffer_vec_add_kernel1(int *a,int *b,int *c,int inc)
{
  static int __m_a[10000];
  static int __m_b[10000];
  static int __m_c[10000];
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "a", "10000 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (a != 0) {
      memcpy((void *)(__m_a + 0),(const void *)a,10000 * sizeof(int ));
    }
     else {
      printf("Error! Detected null pointer 'a' for external memory.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "a");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "b", "10000 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (b != 0) {
      memcpy((void *)(__m_b + 0),(const void *)b,10000 * sizeof(int ));
    }
     else {
      printf("Error! Detected null pointer 'b' for external memory.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "b");
    
#pragma ACCEL debug fflush(stdout);
  }
}

void __merlin_read_buffer_vec_add_kernel1(int *a,int *b,int *c,int inc)
{
  static int __m_a[10000];
  static int __m_b[10000];
  static int __m_c[10000];
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy out", "c", "10000 * sizeof(int )");
    
#pragma ACCEL debug fflush(stdout);
    if (c != 0) {
      memcpy((void *)c,(const void *)(__m_c + 0),10000 * sizeof(int ));
    }
     else {
      printf("Error! Detected null pointer 'c' for external memory.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy out", "c");
    
#pragma ACCEL debug fflush(stdout);
  }
}

void __merlin_execute_vec_add_kernel1(int *a,int *b,int *c,int inc)
{
}