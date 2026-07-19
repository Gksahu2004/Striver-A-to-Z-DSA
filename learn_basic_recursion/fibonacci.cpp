#include<bits/stdc++.h>
using namespace std;

int printFibonacci(int n){
    if (n==1 or n==2) return 1;

    return printFibonacci(n-1) + printFibonacci(n-2);
}

int main(){

    int n;
    cout<< "Enter a number: ";
    cin>> n;

    cout << printFibonacci(n);

    return 0;
}