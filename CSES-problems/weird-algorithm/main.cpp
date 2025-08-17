/*  
    if the input n is even then 
    divide it by 2 else if odd
    multiply it by 3 and add 1
    even -> n = n / 2
    odd  -> n = (3 * n) + 1
*/
#include <iostream>
using namespace std;

int main(){
    long long n; cin >> n;
    // loop over n until the base case which is 1
    while (n > 1){
        cout << n << ' ';
        // check if n is odd
        if(n % 2 == 0) n = n / 2;
        else n = (3 * n) + 1;
    }
    cout << n << ' ';
    return 0;
}