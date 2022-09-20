# Department of Computing

**CS250: Data Structure and Algorithms**

**Class: BSCS 11A&C**

**Course Instructor: Dr. Yasir Faheem**

# Lab 2: Pointers & Array-based Implementation of Lists

**Part One: Revision of Pointers in C++**

**Introduction**

This lab is about pointers, memory occupied by variables, and dynamic vs static memory allocation.

**Objectives**

This lab will revise the concepts learnt by students in the previous semesters.

**Tools/Software Requirement**

Visual Studio C++, Eclipse C++ or any other IDE.

**Description**

Pointers are used to point towards a particular memory address. In this lab, we will use the pointers and perform tasks with the help of them.

**Lab Tasks**

You are required to upload the lab tasks on the LMS and the name of that tasks must be in this format YourFullName\_reg#.cpp

Remember to comment your code properly. Inappropriate or no comment will result in the deduction of marks.

**Task 1:** Write output of the following C++ codes in your document without executing it.

**Example code a)**

int a;

int b;

int \*p=&a;

int \*q=&b;

a=20;

b=35;

p=q;

\*p=83;

cout\<\<"a : "\<\<a\<\<" b: "\<\<b\<\<endl;

cout\<\<\*p\<\<" "\<\<\*q\<\<endl;

**Output:**

**a : 20 b: 83**

**83 83**

**Example code b)**

int x[4] = {0,4,6,9};
 int \*p, a=3;
 p=x;
 (\*p)++;
 cout\<\<\*p\<\<endl;
 cout\<\<\*(p+1)\<\<endl;
 p++;
 \*p=\*p+a;
 cout\<\<\*p\<\<endl;
 p=p+2; //What is happening here?
 cout\<\<\*p\<\<endl;

**Output:**

1

4

7

9

**Example code c)**

int a, \*p, \*q;

int arr[4]= {0};

p=arr;

q=p;

\*p=4;

for(int i=0; i\<3; i++){

a=\*p;

p++;

\*p=(a+i);

}

for (int j=0; j\<4; j++){

cout\<\<\*q\<\<" ";

q++;

}

**Output:**

4 4 5 7

**Task 2:**

int a=5, b=10;

int \*pa=&a; //pa and pb are pointer variables of type int.

int \*pb=&b;

int \*\*ppa=&pa; //ppa and ppb are called double pointers or pointers-to-pointers.

int \*\*ppb=&pb;

1. Write code of a function that swaps values of variables a and b. Input to the function should be the address of both the variables.
2. Write code of a function that swaps values of pointer variables pa and pb. Input to the function should be the address of both the pointer variables.
3. Write code of a function that swaps values of the variables a and b using pointer-to-pointer variables ppa and ppb.

**Task 3:**

int list[5]={3,6,9,12,15};

int \*pArr= list;

Your task is to write a piece of code that prints all values stored in the array **list** using only pointer variable pArr. Do not use the conventional way of printing values by numbering indexes.

**Task 4:** Write code to find the memory in bytes occupied by int, long, double, float and char.