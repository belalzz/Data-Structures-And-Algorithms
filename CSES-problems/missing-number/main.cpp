/*
    the summation of n is all numbers 1 to n
    to get missing number:
    sum(n) - (my numbers) = the missing number
*/
#include <iostream>
using namespace std;

int main(){
    long long n; cin >> n;
    long long sum = (n) * (n + 1) / 2;
    long long sumd = 0;
    for (int i = 0; i < n - 1; ++i){
        long long x; cin >> x;
        sumd += x;
    }
    cout << sum - sumd;
    return 0;
}