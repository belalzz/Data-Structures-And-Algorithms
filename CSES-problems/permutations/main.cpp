/*
    to get always a beautiful permutation
    you can represent the odd values then even values
    in your sequence:
*/
#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION"; return 0;
    }
    for (int i = n - 1; i >= 1; i -= 2){
        cout << i << ' ';
    }
    for (int i = n; i >= 1; i -= 2){
        cout << i << ' ';
    }
    return 0;
}
