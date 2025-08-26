/*
    In this problem we need the number of possible values
    provided by a binary string with length n:
    result = 2^n
    Each bit has two possible values,
    so total possibilities = 2 ^ n.
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
#define ll long long

ll fast_power(ll n, ll p){
    n %= MOD;
    if (p == 0) return 1;
    else if (p == 1) return n;
    if (p % 2 == 0){
        return fast_power((n * n ) % MOD, p / 2) % MOD;
    }else{
        return (n * fast_power((n * n) % MOD, (p - 1)/ 2)) % MOD;
    }
}

int main(){
    long long n; cin >> n;
    cout << fast_power(2, n);
    return 0;
}