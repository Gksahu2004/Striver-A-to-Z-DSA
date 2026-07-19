#include<bits/stdc++.h>
using namespace std;

void print1ToN(int i, int n){
    if (i>n) return;

    print1ToN(i+1, n);
    cout<< i << " ";
}

int main(){

    int i = 1, n;
    cout<< "Enter a number: ";
    cin>> n;

    print1ToN(i,n);

    return 0;
}