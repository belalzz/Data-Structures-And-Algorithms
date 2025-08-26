/*
    In this problem we want to get the trailing zeros
    resulted from n! 
    how to get em -> first approach to divide value by 10 to get number
    of zeros but the value may get > 10^9 so 
    we get how many values is divisible by 10
    but we lost values that has 2 * 5 so we get 
    the value by number divisible by 5 as no 10 will be created with out 5
    so: we take count += n / 5 while n != 0
    1st iteration we got number of values divisible by 5
    2nd iteration we got number of values divisible by 25
    and so on.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int trailingZeros(ll n){
    int cnt = 0;
    while (n){
        cnt += n / 5;
        n /= 5;
    }
    return cnt;
}

int main(){
    ll n; cin >> n;
    cout << trailingZeros(n);
    return 0;
}