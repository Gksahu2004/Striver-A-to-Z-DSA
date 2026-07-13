// You are given an integer n. You need to check whether the number is a palindrome number or not. Return true if it's a palindrome number, otherwise return false.

#include <bits/stdc++.h>

using namespace std;

string palindromeCheck(int n){
    int orgNum = n;
    string num = to_string(n);
    reverse(num.begin(), num.end());
    int revnum = stoi(num);
    if (orgNum == revnum) return "true";
    else return "false";
}

int main(){

    int n;
    cout<< "Enter a number: ";
    cin>> n;

    string flag = palindromeCheck(n);
    cout<< "palindrome or not: " << flag << endl;

    return 0;
}