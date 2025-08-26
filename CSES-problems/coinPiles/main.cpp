/*
    In this problem we found that we remove each time 3 coins from
    both so we add them up and the result if divisible by 3 and 
    the smaller value multiplied by 2 >= bigger value
    must be balanced visualize it as if the smaller amount will run out very fast.
*/

#include <bits/stdc++.h>
#define fastio cin.tie(nullptr); cin.sync_with_stdio(false);
#define ll long long
using namespace std;

int main(){
    fastio
    int t; cin >> t;
    while(t--){
        ll a, b; cin >> a >> b;
        ll ab = a + b;
        if (ab % 3 == 0 && min(a, b) * 2 >= max(a, b)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}