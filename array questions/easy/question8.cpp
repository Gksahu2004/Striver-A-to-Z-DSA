// linear search

#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int x){
    for(int i = 0; i<n; i++){
        if(arr[i] == x) return i;
    }
    return -1;
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

    int x;
    cout<< "Enter the searching number: ";
    cin>> x;

    int index = linearSearch(arr,n,x);
    if(index != -1){
        cout<< "found at index : " << index << endl;
    }
    else cout<< "Not found";


    return 0;
}