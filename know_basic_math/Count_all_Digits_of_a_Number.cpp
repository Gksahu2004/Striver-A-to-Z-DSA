// You are given an integer n. You need to return the number of digits in the number.
// The number will have no leading zeroes, except when the number is 0 itself.


#include <bits/stdc++.h>

using namespace std;

int countDigit(int n){
    int count = 0;
    do{
        count++;
        n /= 10;
    }while(n>0);
    return count;
}

int main(){

    int n;
    cout<< "Enter a number: ";
    cin>> n;

    int count = countDigit(n);
    cout<< "total digit in this number is: " << count<< endl;

    return 0;
}