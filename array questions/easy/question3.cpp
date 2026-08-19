// array sorted or not

#include<bits/stdc++.h>
using namespace std;

string sorted(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        if (arr[i]>arr[i+1]){
            return "false";
        }
    }
    return "true";
}

int main(){

    int n;
    cout<< "Enter the size of array: ";
    cin>> n;

    cout<< "Enter all the values of array" << endl;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }

    cout << sorted(arr, n) << endl;

    return 0;
}