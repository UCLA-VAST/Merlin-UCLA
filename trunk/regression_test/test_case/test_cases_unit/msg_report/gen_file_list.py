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
#!/bin/python
# -*- coding:utf-8 -*-

from __future__ import print_function
import os
import subprocess
import multiprocessing

project_path = []
empty_project_path = []
for dirpath, dirnames, filenames in os.walk('.'):
    if 'Makefile' in filenames:
        if'run.tgz' in filenames:
            project_path.append(dirpath)
        else:
            empty_project_path.append('# ' + dirpath)
            print(dirpath + 'have no run.tgz file')

with open('file_list', 'w') as f:
    f.write('\n'.join(empty_project_path))
    f.write('\n'.join(project_path))
