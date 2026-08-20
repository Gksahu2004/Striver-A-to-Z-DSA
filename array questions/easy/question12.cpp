// Find the number that appears once, and other numbers twice.


#include<bits/stdc++.h>
using namespace std;


// brute force (using nested for loop)
// TC = O(N x N)
// SC = O(1)
int numWithOneOccurence1(int arr[], int n){
    for(int  i = 0; i<n; i++){
        int num = arr[i];
        int count = 0;
        for (int j = 0; j<n; j++){
            if (arr[j] == num) count++;
        }
        if (count == 1) return num;
    }
}


// better approach (using mapping)
// TC = O(NlogM) + O(N/2 + 1)   HERE M = SIZE OF MAP = N/2 + 1
// TC = O(Nlog(N/2 + 1)) + O(N/2 + 1)
// SC = O(N/2 + 1)
int numWithOneOccurence2(int arr[], int n){
    map <long long, int> mpp;
    for(int i = 0; i<n; i++){
        mpp[arr[i]] +=1;
    }
    for (auto it: mpp){
        if(it.second == 1) return it.first;
    }
}

// optimal approach (using xor function)
// TC = O(N)
// SC = O(1)
int numWithOneOccurence3(int arr[], int n){
    int num = 0;
    for(int i = 0; i<n; i++){
        num = num ^ arr[i];
    }
    return num;
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

    int num = numWithOneOccurence1(arr, n);
    // int num = numWithOneOccurence2(arr, n);
    // int num = numWithOneOccurence3(arr, n);

    cout<< "number with one occurence is: " << num << endl;

    return 0;
}