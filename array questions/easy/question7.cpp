// moving all zeros to end of the array

#include<bits/stdc++.h>
using namespace std;


// brute force
// method 1
void moveAllZero1(int arr[], int n){
    int temp[n];
    int count = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == 0) count++;
    }
    int j = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] != 0){
            temp[j] = arr[i];
            j++;
        }
    }
    for(int i = 0; i<n; i++){
        if (i<n-count) arr[i] = temp[i];
        else arr[i] = 0;
    }
}

// better solution
// method 2
// TC = n + x + n-x = 2n
// SC = n
void moveAllZero2(int arr[], int n){
    vector <int> vec;
    for(int i = 0; i<n; i++){
        if(arr[i] != 0){
            vec.push_back(arr[i]);
        }
    }
    int nonZero = vec.size();
    for(int i = 0; i<nonZero; i++){
        arr[i] = vec[i];
    }
    for(int i = nonZero; i<n; i++){
        arr[i] = 0;
    }
}

// optimal
// method 3
// TC = N
// SC = 1 (no extra space but using the already given array)
void moveAllZero3(int arr[], int n){
    int j = -1;
    for(int i = 0; i<n; i++){
        if (arr[i] == 0){
            j = i;
            break;
        }
    }
    for(int i = j+1; i<n; i++){
        if (arr[i]!=0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
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

    // moveAllZero1(arr, n);

    // moveAllZero2(arr, n);

    moveAllZero3(arr, n);


    for(int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }

    return 0;
}