/*
    INSERTION SORT
    -----
    Time Complexity  : O(n^2)
    memory Complexity: O(1)
    -----
    the algorithm -> iterating over Arr[i]
    and save its value in a variable "key"
    and compare each value before it with key
    if its greater than the key so the it shift right
    and the last step is by assigning the value of the key
    in which no greater than key in prv sub-array
*/
#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& A){
    int n = A.size();
    for (int i = 1; i < n; ++i){
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main(){
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    insertion_sort(A);
    for(int x: A) cout << x << ' ';
    return 0;
}