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
/************************************************************************************
 Merlin Compiler (TM) Version 2018.2.dev (b707aefad.8227)
 Built Mon Jun 25 19:59:39 2018 -0700
 Copyright (C) 2015-2018 Xilinx, Inc. All Rights Reserved.
************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
extern int __merlin_init(const char * bitstream);
extern int __merlin_release();
extern void __merlin_ellpack_kernel(double nzval[(1 << 12) * (1 << 9)],int cols[(1 << 12) * (1 << 9)],double vec[1 << 12],double out[1 << 12]);
#ifdef __cplusplus
}
#endif