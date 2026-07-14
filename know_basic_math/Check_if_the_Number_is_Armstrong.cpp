// You are given an integer n. You need to check whether it is an armstrong number or not. Return true if it is an armstrong number, otherwise return false.

// An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.


#include <bits/stdc++.h>

using namespace std;

int countDigit(int n){
    string num = to_string(n);
    int count = num.size();
    cout<< count<< endl;
    return count;
}

int digitSum(int n, int noOfDigit){
    int sum = 0, ld;
    while (n>0){
        ld = n%10;
        cout<< ld << " ";
        sum += pow(ld, noOfDigit);
        cout<< sum << " ";
        n /= 10;
    }
    cout<< sum << endl;
    return sum;
}

string armstrongCheck(int n){
    int num = n;
    int noOfDigit = countDigit(n);
    int newNum = digitSum(num, noOfDigit);
    if (newNum == num) return "true";
    else return "false";
}

int main(){

    int n;
    cout<< "Enter a number: ";
    cin>> n;

    string flag = armstrongCheck(n);
    cout<< "armstrong or not: " << flag << endl;

    return 0;
}