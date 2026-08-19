// second largest element of the array

#include<bits/stdc++.h>
using namespace std;

void second_largest(int arr[], int n){
    int largest = INT_MIN;
    int second_largest;
    for(int i = 0; i<n; i++){
        if(largest<arr[i]){
            second_largest = largest;
            largest = arr[i];
        }
    }
    cout<< endl;
    cout<<"largest: "<< largest<< endl;
    cout<<"second largest: "<< second_largest<< endl;
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

    second_largest(arr, n);

    return 0;
}