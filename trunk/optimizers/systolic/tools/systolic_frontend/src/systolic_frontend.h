// (C) Copyright 2016-2021 Xilinx, Inc.
// All Rights Reserved.
//
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.



#ifndef TRUNK_OPTIMIZERS_SYSTOLIC_TOOLS_SYSTOLIC_FRONTEND_SRC_SYSTOLIC_FRONTEND_H_
#define TRUNK_OPTIMIZERS_SYSTOLIC_TOOLS_SYSTOLIC_FRONTEND_SRC_SYSTOLIC_FRONTEND_H_

#include <list>
#include <utility>
#include <vector>
#include "SystolicData.h"

extern char workingStrMap[];
extern int currWorkingStr;

extern std::ofstream dseLog;

void SystolicArrayLoopExploration(
    CSageCodeGen *codegen,
    std::list<std::vector<std::pair<void *, int>>> *candidates,
    SystolicData *sysDataImpl);

void FeederLoopExploration(
    CSageCodeGen *codegen,
    std::list<std::vector<std::pair<void *, int>>> *sysCandidates,
    std::vector<SystolicData *> *dataImpls, int step);

void *CreateSystolicArrayFunc(CSageCodeGen *codegen,
                              std::vector<void *> vecPreprocess,
                              std::vector<void *> vecPostprocess,
                              SystolicData *sysData, int index);

#endif  // TRUNK_OPTIMIZERS_SYSTOLIC_TOOLS_SYSTOLIC_FRONTEND_SRC_SYSTOLIC_FRONTEND_H_
