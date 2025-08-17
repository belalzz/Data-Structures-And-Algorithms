/*
    we can get min number of inc to each value to obtain increasing array
    by count difference between it and the max value before it
    sum += max - xi
*/

#include <iostream>
using namespace std;

int main(){
    long long sum = 0;
    long long max_val = 0;
    int n; cin >> n;
    while (n--){
        long long x; cin >> x;
        max_val = max(max_val, x);
        sum += max_val - x;
    }
    cout << sum;
    return 0;
}
