/*
    we count each character in the string
    if number of chars repeated odd times > 1 then can't be
    palindrome
    else we add half number of char to the right of a and reverse it to b
    then we add the middle string that contain odd repeated character
*/

#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

bool can_be_palindrome(vector<int>& freq){
    int odd_count = 0;
    for (auto v : freq){
        if (v % 2 != 0){
            odd_count++;
            if(odd_count == 2) return false;
        }
    }
    return true;
}

int main(){
    fastio
    vector<int> freq(26, 0);
    string s; cin >> s;
    for (char c : s){
        freq[c - 'A']++;
    }
    if(!can_be_palindrome(freq)){
        cout << "NO SOLUTION";
        return 0;
    }
    string left, middle;
    for (int i = 0; i < 26; ++i){
        if (freq[i] % 2 == 0){
            left.append(freq[i] / 2, char(i + 'A'));
        }else{
            left.append(freq[i] / 2, char(i + 'A'));
            middle.append(freq[i] % 2, char(i + 'A'));
        }
    }
    string right = left;
    reverse(right.begin(), right.end());
    cout << left << middle << right;
    return 0;
}