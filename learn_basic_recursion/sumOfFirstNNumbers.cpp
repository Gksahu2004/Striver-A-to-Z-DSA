#include<bits/stdc++.h>
using namespace std;

int sumoffirstNnumbers(int n){
    if (n==1) return 1;

    return n + sumoffirstNnumbers(n-1);
}

int main(){

    int i = 1, n, sum = 0;
    cout<< "Enter a number: ";
    cin>> n;

    int sumofnums = sumoffirstNnumbers(n);
    cout<< sumofnums << endl;

    return 0;
}