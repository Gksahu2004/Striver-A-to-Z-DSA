// largest element of the array

#include<bits/stdc++.h>
using namespace std;

void largest(int arr[], int n){
    int largest = INT_MIN;
    for(int i = 0; i<n; i++){
        if(largest<arr[i]){
            largest = arr[i];
        }
    }
    cout<<"largest: "<< largest<< endl;
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

    largest(arr, n);

    return 0;
}