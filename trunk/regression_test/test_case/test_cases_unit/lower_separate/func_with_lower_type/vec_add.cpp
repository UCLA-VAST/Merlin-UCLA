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
template<typename T>
class A {
  T a;
  public:
  void incr() {
    a++;
  }
  T get() const {
    return a;
  }
  void set(T val) {
    a = val;
  }
};

void sub( A<int> *a) {
  a[0].incr();
}
#pragma ACCEL kernel
void top(int *a) {
  A<int> tmp;
  tmp.set(a[1]);
  sub(&tmp);
  a[2] = tmp.get();
}
