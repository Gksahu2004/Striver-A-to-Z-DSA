#include <bits/stdc++.h>

using namespace std;

void allDivisor(int n){
    for(int i = 1; i<=n; i++){
        if(n%i==0) cout<< i << " ";
    }
}

int main(){

    int n;
    cout<< "Enter a number: ";
    cin>> n;

    allDivisor(n);

    return 0;
}