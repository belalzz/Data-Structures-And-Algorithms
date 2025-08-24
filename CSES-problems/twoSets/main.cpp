/*
    1st must make sure that the sequence
    can make two sequence with same sum
    so the we get sum of n
    total = (n * (n + 1)) / 2
    then we have to make sure that it can be
    divided in two sets so 
    if its not divisible by 2 -> NO
    else
    we save the setSum = totalSum / 2;
    iterate n .. 1:
    if the value <= setSum insert in set1 and setSum -= i
    else put in the other set
*/


#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long n; cin >> n;
    long long s = (n * (n + 1)) / 2;
    long long sum1 = s / 2;
    if (!(s % 2 == 0)){
        cout << "NO";
        return 0;
    }

    vector<long long> s1, s2;
    for (long long i = n; i >= 1; --i){
        if (i <= sum1){
            sum1 -= i;
            s1.push_back(i);
        }else{
            s2.push_back(i);
        }
    }
    cout << "YES\n";
    cout << s1.size() << '\n';
    for (auto k: s1){
        cout << k << ' ';
    }
    cout << "\n" << s2.size() << "\n";
    for (auto k: s2){
        cout << k << ' ';
    }

    return 0;
}