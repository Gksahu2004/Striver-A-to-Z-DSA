// left rotate an array by one place

#include<bits/stdc++.h>
using namespace std;

void rotatebyone(int arr[], int n){
    int value = arr[0];
    int i = 1;
    for(; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[i-1] = value;
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

    rotatebyone(arr, n);

    for(int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }

    return 0;
}