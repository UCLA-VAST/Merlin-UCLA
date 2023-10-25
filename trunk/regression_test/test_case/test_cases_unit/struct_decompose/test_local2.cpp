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

const int N = 100;

class Test {
private:
  int a;
  char b;
public:
  void set_a(int n) {a = n;}
  void set_b(char c) {b = c;}
  int get_a() {return a;}
  int get_b() {return b;}
};

#pragma ACCEL kernel
void top(Test *a) {
#pragma ACCEL interface variable=a depth=100
	int i;
	class Test b;

	 b.set_a(1);
	b.set_b('b');
  for (i = 0; i < N; ++i) {
    a[i].set_a(a[i].get_a() + b.get_a());
	a[i].set_b(a[i].get_b() + b.get_b());
  }

  return ;
}

int main() {
	int i;

  Test *a = new Test[N];

  for (i = 0; i < N; ++i)
    a[i].set_a(i);

  top(a);

  delete [] a;

  return 0;

}