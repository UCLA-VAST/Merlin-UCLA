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
#include "aes.h"
#include <string.h>
int INPUT_SIZE = (sizeof(struct bench_args_t ));
void aes256_encrypt_ecb_kernel(aes256_context *ctx,unsigned char k[32],unsigned char buf[16]);
extern int __merlin_include__LB___merlinhead_kernel_top_h_0;
#include "__merlinhead_kernel_top.h"
extern int __merlin_include__LE___merlinhead_kernel_top_h_0;
extern int __merlin_include__LB___merlintask_top_h_1;
#include "__merlintask_top.h"
extern int __merlin_include__LE___merlintask_top_h_1;

void run_benchmark(void *vargs)
{
  struct bench_args_t *args = (struct bench_args_t *)vargs;
  
#pragma ACCEL task name="aes256_encrypt_ecb"
{
    __merlin_init("kernel_top.aocx");
    aes256_encrypt_ecb(args);
  }
}
/* Input format:
%%: Section 1
uint8_t[32]: key
%%: Section 2
uint8_t[16]: input-text
*/

void input_to_data(int fd,void *vdata)
{
  struct bench_args_t *data = (struct bench_args_t *)vdata;
  char *p;
  char *s;
// Zero-out everything.
  memset(vdata,0,sizeof(struct bench_args_t ));
// Load input string
  p = readfile(fd);
// Section 1: key
  s = find_section_start(p,1);
  parse_uint8_t_array(s,data -> k,32);
// Section 2: input-text
  s = find_section_start(p,2);
  parse_uint8_t_array(s,data -> buf,16);
}

void data_to_input(int fd,void *vdata)
{
  struct bench_args_t *data = (struct bench_args_t *)vdata;
// Section 1
  write_section_header(fd);
  write_uint8_t_array(fd,data -> k,32);
// Section 2
  write_section_header(fd);
  write_uint8_t_array(fd,data -> buf,16);
}
/* Output format:
%% Section 1
uint8_t[16]: output-text
*/

void output_to_data(int fd,void *vdata)
{
  struct bench_args_t *data = (struct bench_args_t *)vdata;
  char *p;
  char *s;
// Zero-out everything.
  memset(vdata,0,sizeof(struct bench_args_t ));
// Load input string
  p = readfile(fd);
// Section 1: output-text
  s = find_section_start(p,1);
  parse_uint8_t_array(s,data -> buf,16);
}

void data_to_output(int fd,void *vdata)
{
  struct bench_args_t *data = (struct bench_args_t *)vdata;
// Section 1
  write_section_header(fd);
  write_uint8_t_array(fd,data -> buf,16);
}

int check_data(void *vdata,void *vref)
{
  struct bench_args_t *data = (struct bench_args_t *)vdata;
  struct bench_args_t *ref = (struct bench_args_t *)vref;
  int has_errors = 0;
// Exact compare encrypted output buffers
  has_errors |= memcmp((&data -> buf),(&ref -> buf),16 * sizeof(unsigned char ));
// Return true if it's correct.
  return !has_errors;
}
