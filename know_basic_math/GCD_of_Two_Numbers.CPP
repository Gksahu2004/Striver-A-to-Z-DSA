// You are given two integers n1 and n2. You need find the Greatest Common Divisor (GCD) of the two given numbers. Return the GCD of the two numbers.

// The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both of the integers.


#include <bits/stdc++.h>

using namespace std;

int gcdOfTwo(int m, int n){
    int minoftwo = min(m,n);
    int gcd;
    for (int i = minoftwo; i>=1; i--){
        if (m%i==0 and n%i==0){
            gcd = i;
            break;
        }
    }
    return gcd;
}

int main(){

    int m;
    cout<< "Enter first number: ";
    cin>> m;

    int n;
    cout<< "Enter second number: ";
    cin>> n;

    if (m <= 0 and n <= 0){
        int gcd = gcdOfTwo(m, n);
        cout<< "GCD OF THESE TWO IS: " << gcd << endl;
    }
    else cout<< "you can not enter zero or negative number" << endl;

    return 0;
}