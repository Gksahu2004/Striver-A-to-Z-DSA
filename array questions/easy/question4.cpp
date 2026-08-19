// remove duplicates from a sorted array

#include<bits/stdc++.h>
using namespace std;

// brute force method
// method 1 (using set function)
int remove_dup1(int arr[], int n){
    set<int> st;
    for(int i = 0; i<n;i++){
        st.insert(arr[i]);
    }
    cout<< "set size: " << st.size() << endl;
    int index = 0;
    for(auto it: st){
        arr[index] = it;
        index++;
    }
    return index;
}

// method 2 (using map function)
int remove_dup2(int arr[], int n){
    map <int,int> mpp;
    for(int i = 0; i<n; i++){
        mpp[arr[i]]++;
    }
    int index = 0;
    for(auto it: mpp){
        arr[index] = it.first;
        index++;
    }
    return index;
}

// optimal method
// method 3 (using two pointer approach)
int remove_dup3(int arr[], int n){
    int i = 0, j = 1;
    while(j<n){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
        j++;
    }
    return i+1;
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

    // int idx = remove_dup1(arr, n);
    // int idx = remove_dup2(arr, n);
    int idx = remove_dup3(arr, n);


    for(int i = 0; i<idx; i++){
        cout<< arr[i] << " ";
    }

    return 0;
}