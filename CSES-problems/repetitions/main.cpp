/*
    to get longest subseq of same char
    we use double pointer:
    l point to the char and r expand over the same value
    and compare max with the range we get
    then l = r, in which r is the new value
    and then inc r
*/

#include <iostream>
using namespace std;

int main(){
    string s; cin >> s;
    size_t l = 0, r = 0, n = s.length(), res = 0;
    while (r < n){
        while(s[r] == s[l] && r < n){
            r++;
        }
        res = max(res, (r - l));
        l = r;
        r++;
    }
    cout << res;
    return 0;
}
