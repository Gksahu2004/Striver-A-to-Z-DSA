// Next Permutation

#include<bits/stdc++.h>
using namespace std;

// optimal solution
// TC = O(3N)
// SC = O(1)
void nextPermuatation(int arr[], int n){
    int breakpoint;
    int flag = 0;
    for(int i = n-2; i>=0; i--){
        if(arr[i] < arr[i+1]){
            breakpoint = i;
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        for(int i = n-1; i>=breakpoint; i--){
            if(arr[i] > arr[breakpoint]){
                swap(arr[i], arr[breakpoint]);
                break;
            }
        }
        reverse(arr+breakpoint+1, arr+n);
    }
    else{
        reverse(arr, arr+n);
    }
}



int main(){

    int n;
    cout<< "Enter the size of array: ";
    cin>> n;

    cout<< "Now enter all the values of array one by one:" << endl;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>> arr[i];
    }

    nextPermuatation(arr, n);

    cout<< "Next permutation is:" << endl;
    for(int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }

    return 0;
}