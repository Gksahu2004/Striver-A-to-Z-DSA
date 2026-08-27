// Leaders in an Array


#include<bits/stdc++.h>
using namespace std;


// brute force
// TC = O(N*N) = O(N^2) IF WE DO NOT COUNT THE STORING OF LEADERS IN VECTOR
// SC = O(N) IF VECTOR NOT INCLUDED
// because vector is used to show the output not to solve the question
void printleaders1(int arr[], int n){
    vector<int> vec;
    for(int i = 0; i<n-1; i++){
        int leader = arr[i];
        int flag = 0;
        for(int j = i+1; j<n; j++){
            if(leader<arr[j]){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            vec.push_back(arr[i]);
        }
    }
    vec.push_back(arr[n-1]);
    cout<< "all leaders are: ";
    for(auto it: vec){
        cout<< it << " ";
    }
}


// OPTIMAL SOLUTION
// TC = O(N)
// SC = O(1) IF VECTOR NOT INCLUDED
void printleaders2(int arr[], int n){
    int max = INT_MIN;
    for(int i = n-1; i>=0; i--){
        if(arr[i] > max){
            cout<< arr[i] << " ";  // we can also store in vector instead of just printing like previous
            max = arr[i];
        }
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

    cout<< "all leaders are: ";
    printleaders1(arr, n);
    // printleaders2(arr, n);


    return 0;
}