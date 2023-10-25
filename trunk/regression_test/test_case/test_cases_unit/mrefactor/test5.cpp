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
#include<array>
class A {
  std::array<int, 10> data;
  public:
    int get() const {
      return data[11];
    }
};

template <typename T> 
void f(std::array<T, 10> &a, T b) {
  a[0] = b;
}

int main() {
  A a;
  int r = a.get();
  std::array<int, 10> c;
  f(c, 0);
  std::array<int, 10> d;
  d[0] = 0;
  return 0;
}
