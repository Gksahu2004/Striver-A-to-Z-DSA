#include<bits/stdc++.h>
using namespace std;

void stringPallindromeCheck(int m, int n, string str){
    if(m>n){
        cout<< "pallindrome";
        return;
    }

    if (str[m] != str[n]){
        cout<< "not pallindrome";
        return;
    }
    
    stringPallindromeCheck(m+1, n-1, str);
}

int main(){

    string str;
    cout<< "Enter a string: ";
    getline(cin, str);

    int length = str.size();

    stringPallindromeCheck(0, length-1, str);

    return 0;
}