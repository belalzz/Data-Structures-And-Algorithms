/*
    LINEAR SEARCH
    -----
    Time Complexity  :
    Best case: omega(1) to find it in the first element
    average case: theta(n) to find it within the n elements
    worst case: not find it n so iterate over n elements
    -----
    memory Complexity: O(1)
    -----
    the algorithm -> iterating over Array
    if the current element equal key return true
    else return false.
*/
#include <iostream>
#include <vector>

using namespace std;

bool linear_search(vector<int>& A, int key){
    int n = A.size();
    for (int i = 0; i < n; ++i){
        if (A[i] == key) return true;
    }
    return false;
}

int main(){
    vector<int> A({2, 4, 5, 3, 1, -2});
    int key;
    cout << "Enter value to search on: "; cin >> key;
    cout << (linear_search(A, key)? "FOUND\n": "NOT FOUND\n");
    return 0;
}