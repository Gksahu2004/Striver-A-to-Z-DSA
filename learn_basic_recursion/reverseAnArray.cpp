#include<bits/stdc++.h>
using namespace std;

void reverseAnArray(int m, int n, int arr[]){
    if(m>n) return;

    int temp = arr[m];
    arr[m] = arr[n];
    arr[n] = temp;
    reverseAnArray(m+1, n-1, arr);
}

int main(){

    int n;
    cout<< "Enter array size: ";
    cin>> n;

    int arr[n];
    for (int i = 0; i<n; i++){
        cout<< "Enter value of index "<< i << " : ";
        cin>> arr[i];
        cout<< endl;
    }

    reverseAnArray(0, n-1, arr);

    for (int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }

    return 0;
}