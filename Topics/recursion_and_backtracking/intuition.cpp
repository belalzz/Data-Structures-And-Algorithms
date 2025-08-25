#include <iostream>
#include <unordered_map>
using namespace std;

/*
what's recursion?
    Function calling itself...

*/
/*
Two types of recursion:
    1. Direct recursion
    ex: foo(){
        foo();
    }
    2. Indirect recursion
    ex:
    f1(){
        f2();
    }
    f2(){
        f1();
    }
*/

/*
Recursive terminate by
a certain condition or it will call
stack until overflow
so must be limited by a base case
ex:
void foo(int n){
    if (n == 0) return; // this is the base case
    foo(n-1); // this call makes a branch or a tree
}

Recursion is made up of 2 parts:
base case
statement
*/

int fib(int n)
{
    if (n == 1 || n == 0)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}

int main()
{
    cout << fib(10);
    return 0;
}
