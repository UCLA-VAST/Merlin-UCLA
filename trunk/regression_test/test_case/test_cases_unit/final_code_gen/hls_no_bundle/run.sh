#(C) Copyright 2016-2021 Xilinx, Inc.
#All Rights Reserved.
#
#Licensed to the Apache Software Foundation (ASF) under one
#or more contributor license agreements.  See the NOTICE file
#distributed with this work for additional information
#regarding copyright ownership.  The ASF licenses this file
#to you under the Apache License, Version 2.0 (the
#"License"); you may not use this file except in compliance
#with the License.  You may obtain a copy of the License at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
#Unless required by applicable law or agreed to in writing,
#software distributed under the License is distributed on an
#"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
#KIND, either express or implied.  See the License for the
#specific language governing permissions and limitations
#under the License. (edited)
mars_opt  __merlinwrapper_vec_add_kernel.cpp __merlinkernel_vec_add_kernel.cpp  -e c -p final_code_gen -a cstd=c99 -a cxxstd=c++11 -a impl_tool=sdaccel -a mode=opencl -a naive= -a effort=standard -a volatile_flag= -a explicit_bundle= -a pure_kernel=off -a debug_mode=debug   -I . -a cflags="-D XILINX -D__SYNTHESIS__  -D_MARS_COMPILER_FLOW_ " -a tool_version=vitis_hls

