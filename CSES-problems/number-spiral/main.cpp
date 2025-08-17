/*
    to get the value in the spiral function:
    take the greater position then get its
    square which represent the max value in this
    row or column,
*/
#include <iostream>
using namespace std;
#define ull unsigned long long

bool is_even(ull x){
    return (x % 2 == 0);
}

ull spiral(ull y, ull x){
    ull gr = max(y, x);
    ull base = (gr - 1) * (gr - 1);
    if(is_even(gr)){
        if (x == gr) return base + y;
        else return gr * gr - x + 1;
    }else{
        if (y == gr) return base + x;
        else return gr * gr - y + 1;
    }
}

int main(){
    cin.tie(nullptr); cin.sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        ull y, x; cin >> y >> x;
        cout << spiral(y, x) << '\n';
    }
    return 0;
}
