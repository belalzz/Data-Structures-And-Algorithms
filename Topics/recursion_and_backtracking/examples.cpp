#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;
/*
int n = 2;
void binary_seq(int sum1, int sum2, string s){
    if (s.length() == 2 * n){
        if (sum1 == sum2)
        cout << s << '\n';
        return;
    }
    binary_seq(sum1, sum2, s + "0");
    if (s.size() < n){
        binary_seq(sum1 + 1, sum2, s + "1");
    }else {
        binary_seq(sum1, sum2 + 1, s + "1");
    }
}
*/

int n_char;
string refS;
void possible(string s){
    if (s.length() == n_char){
        cout << s << '\n';
        return;
    }
    for (int i = 0; i < refS.size(); ++i){
        possible(s + refS[i]);
    }
}

int main(){
    refS = "ABC";
    n_char = 3;
    possible("");
    return 0;
}