#include<bits/stdc++.h>
using namespace std;

void printNTo1(int i, int n){
    if (i>n) return;

    printNTo1(i+1, n);
    cout<< i << " ";
}

int main(){

    int i = 1, n;
    cout<< "Enter a number: ";
    cin>> n;

    printNTo1(i,n);

    return 0;
}