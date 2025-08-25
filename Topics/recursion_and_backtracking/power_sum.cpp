#include <iostream>
#include <math.h>
using namespace std;

int cnt = 0;
int N, X;
int nLim;

void recu(int num, int sum){
    if (sum > X || nLim < num) return;
    else if (sum == X) {
        cnt++;
        return;
    }
    recu(num + 1, sum + pow(num, N));
    recu(num + 1, sum);
}

int main(){
    N = 3;
    X = 100;
    nLim = ceil(sqrt(X));
    recu(1, 0);
    cout << cnt;
    return 0;
}
