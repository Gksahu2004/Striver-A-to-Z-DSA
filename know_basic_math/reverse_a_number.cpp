// You are given an integer n. Return the integer formed by placing the digits of n in reverse order.


#include <bits/stdc++.h>

using namespace std;


// // METHOD 1: USING BUILT IN FUNCTIONS
// int reverse(int n){
//     string num = to_string(n);
//     reverse(num.begin(), num.end());
//     int revnum = stoi(num);
//     return revnum;
// }


// // METHOD 2: USING BASIC MATHEMATICS
int reverse(int n){
    int revnum = 0;
    while(n>0){
        int ld = n%10;
        n/=10;
        revnum = revnum * 10 + ld;
    }
    return revnum;
}

int main(){

    int n;
    cout<< "Enter a number: ";
    cin>> n;

    int revnum = reverse(n);
    cout<< "reverse of this number is: " << revnum<< endl;

    return 0;
}