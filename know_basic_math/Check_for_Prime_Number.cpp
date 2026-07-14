#include <bits/stdc++.h>

using namespace std;

void primeOrNot(int n){
    int flag = 0;
    for(int i = 2; i<n; i++){
        if(n%i==0) {
            cout<< "Not prime" << endl;
            flag = 1;
            break;
        }
    }
    if (flag==0) cout<< "prime"<< endl;

}

int main(){

    int n;
    cout<< "Enter a number: ";
    cin>> n;

    if (n>1) primeOrNot(n);
    else if (n==1) cout<< "neither prime nor composite";
    else cout<< "invalid number";

    return 0;
}