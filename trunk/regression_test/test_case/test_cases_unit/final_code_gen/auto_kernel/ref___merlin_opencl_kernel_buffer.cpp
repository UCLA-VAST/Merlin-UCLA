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
#include "__merlin_opencl_kernel_buffer.h"
opencl_kernel __needwun_kernel_kernel;
cl_event __event_needwun_kernel;
opencl_mem __needwun_kernel__SEQA_buffer;
cl_event __event___needwun_kernel__SEQA_buffer;
opencl_mem __needwun_kernel__SEQB_buffer;
cl_event __event___needwun_kernel__SEQB_buffer;
opencl_mem __needwun_kernel__alignedA_buffer;
cl_event __event___needwun_kernel__alignedA_buffer;
opencl_mem __needwun_kernel__alignedB_buffer;
cl_event __event___needwun_kernel__alignedB_buffer;
int __merlin_init_needwun_kernel(){
	#pragma ACCEL debug printf("[Merlin Info] Start create kernel for %s....\n", "needwun_kernel");
	#pragma ACCEL debug fflush(stdout);
	opencl_create_kernel(&__needwun_kernel_kernel, (char *)"needwun_kernel");
	#pragma ACCEL debug printf("[Merlin Info] Successful create kernel for %s....\n", "needwun_kernel");
	#pragma ACCEL debug fflush(stdout);
	#pragma ACCEL debug printf("[Merlin Info] Start create buffer for %s....\n", "SEQA");
	#pragma ACCEL debug fflush(stdout);
	opencl_create_buffer(&__needwun_kernel__SEQA_buffer, (int64_t)1*131072, 2, NULL);
	#pragma ACCEL debug printf("[Merlin Info] Successful create buffer for %s....\n", "SEQA");
	#pragma ACCEL debug fflush(stdout);
	#pragma ACCEL debug printf("[Merlin Info] Start create buffer for %s....\n", "SEQB");
	#pragma ACCEL debug fflush(stdout);
	opencl_create_buffer(&__needwun_kernel__SEQB_buffer, (int64_t)1*131072, 2, NULL);
	#pragma ACCEL debug printf("[Merlin Info] Successful create buffer for %s....\n", "SEQB");
	#pragma ACCEL debug fflush(stdout);
	#pragma ACCEL debug printf("[Merlin Info] Start create buffer for %s....\n", "alignedA");
	#pragma ACCEL debug fflush(stdout);
	opencl_create_buffer(&__needwun_kernel__alignedA_buffer, (int64_t)1*262144, 2, NULL);
	#pragma ACCEL debug printf("[Merlin Info] Successful create buffer for %s....\n", "alignedA");
	#pragma ACCEL debug fflush(stdout);
	#pragma ACCEL debug printf("[Merlin Info] Start create buffer for %s....\n", "alignedB");
	#pragma ACCEL debug fflush(stdout);
	opencl_create_buffer(&__needwun_kernel__alignedB_buffer, (int64_t)1*262144, 2, NULL);
	#pragma ACCEL debug printf("[Merlin Info] Successful create buffer for %s....\n", "alignedB");
	#pragma ACCEL debug fflush(stdout);
	return 0;
}
int opencl_init_kernel_buffer(){
	int __merlin_init_needwun_kernel();
	return 0;
}
int __merlin_release_needwun_kernel(){
	if(__needwun_kernel_kernel) {
		opencl_release_kernel(__needwun_kernel_kernel);
	}
	if(__event_needwun_kernel) {
		opencl_release_event(__event_needwun_kernel);
	}
	if(__needwun_kernel__SEQA_buffer) {
		opencl_release_mem_object(__needwun_kernel__SEQA_buffer);
	}
	if(__needwun_kernel__SEQB_buffer) {
		opencl_release_mem_object(__needwun_kernel__SEQB_buffer);
	}
	if(__needwun_kernel__alignedA_buffer) {
		opencl_release_mem_object(__needwun_kernel__alignedA_buffer);
	}
	if(__needwun_kernel__alignedB_buffer) {
		opencl_release_mem_object(__needwun_kernel__alignedB_buffer);
	}
	return 0;
}
int __merlin_release_kernel_buffer(){
	int __merlin_release_needwun_kernel();
	return 0;
}
int __merlin_wait_kernel_needwun_kernel(){
	opencl_wait_event(__event_needwun_kernel);
	return 0;
}
int __merlin_wait_write_needwun_kernel(){
		opencl_wait_event(__event___needwun_kernel__SEQA_buffer);
	if(__needwun_kernel__SEQA_buffer) {
		opencl_release_mem_object(__needwun_kernel__SEQA_buffer);
	}
		opencl_wait_event(__event___needwun_kernel__SEQB_buffer);
	if(__needwun_kernel__SEQB_buffer) {
		opencl_release_mem_object(__needwun_kernel__SEQB_buffer);
	}
	return 0;
}
int __merlin_wait_read_needwun_kernel(){
		opencl_wait_event(__event___needwun_kernel__alignedA_buffer);
	if(__needwun_kernel__alignedA_buffer) {
		opencl_release_mem_object(__needwun_kernel__alignedA_buffer);
	}
		opencl_wait_event(__event___needwun_kernel__alignedB_buffer);
	if(__needwun_kernel__alignedB_buffer) {
		opencl_release_mem_object(__needwun_kernel__alignedB_buffer);
	}
	return 0;
}
