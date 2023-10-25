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

void func2(int * bb);
void func3(int * bb);
void func4();
void func5(int i, int * a);

#if 1

void test(int *a)
{
    double b[1000];
    //memcpy(b, a, 100*4);

    for (int j = 1; j < 10; j++)
        memcpy(b + 100, a, j*8);
}


void func1(int * a)
{
    int b[1000];
    int b1[1000];
    int b2[1000];
    double b3[1000];
    int b4[1000];
    int b5[1000];
    int b6[1000];
    int b7[1000];
    int b8[1000];
    int b9[1000];
    int j;

    int * c = b;
    int * c1 = b1 + 1;
    c1[-1] = c1[0];
    c[-1] = c[0];

    memcpy(b2, b3, 100*4);
    for (j = 1; j < 10; j++)
        memcpy(b4 + 100, b5, j*4);
    memcpy(b6+300, &(b7[600]), 100*4);
    for (j = 0; j < 10; j++)
        memcpy(b8 + 5*j, b9, 4*4);


    for (int i = 0; i < 100; i++)
    {
        int *d = b;
        int a = d[i];
        int a1 = d[i+1];
        func2(b);
    }
}


void func2(int * bb)
{
    bb[1] = 1;
    int * cc;
    cc = bb;
    //int * cc = bb;

    for (int i = 10; i < bb[3]; i++)
    {
        cc[2] = 0;
        func3(cc);
    }
}

void func3(int * bb)
{
    int * cc;
    cc = bb;

    cc[101];
}


void func4()
{
    int arr[1000];
    for (int i = 0; i < 100; i++)
    {
        func5(i, arr);
    }
}

void func5(int i, int * a)
{
    for (int j = 0; j < 10; j++)
    {
        a[10*i+j];
    }
}
#endif


