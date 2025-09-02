/*
    MERGE SORT
    -----
    Time complexity: 
    theta(n log n)
    memory Complexity: O(n)
    -----
    The algorithm depend on the concept of 
    divide and conquer so we have three stages
    divide: in each step we divide the array into two halves
            from [start .. mid] and [mid + 1 .. end]
    Conquer: tackling each subproblem and sort them
    Combine: combine the answer for the big problem and merge each
            two sorted array in time of n.
    -----
*/
#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& A, int p, int q, int r) {
    vector<int> a(A.begin() + p, A.begin() + q + 1);
    vector<int> b(A.begin() + q + 1, A.begin() + r + 1);

    int i = 0, j = 0, k = p;
    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] <= b[j]) {
            A[k++] = a[i++];
        } else {
            A[k++] = b[j++];
        }
    }
    while (i < (int)a.size()) A[k++] = a[i++];
    while (j < (int)b.size()) A[k++] = b[j++];
}

void merge_sort(vector<int>& A, int p, int r){
    if (p >= r){
        return;
    }
    int q = (p + r) / 2;
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    merge(A, p, q, r);
}

int main(){
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    merge_sort(A, 0, n - 1);
    for(int x: A) cout << x << ' ';
    return 0;
}