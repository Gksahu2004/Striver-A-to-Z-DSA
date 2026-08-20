// 	Find missing number

#include<bits/stdc++.h>
using namespace std;

// brute force (using nested for loop)
// method 1
// TC = O(N x N)
// SC = O(1)
int missingNumber1(int arr[], int n){
    for(int i = 1; i<=n; i++){
        int flag = 0;
        for(int j = 0; j<n-1; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    }
    return -1;
}


// better solution (using hashing)
// method 2
// TC = O(N) + O(N) = O(2N)
// SC = O(N)
int missingNumber2(int arr[], int n){
    int hash[n+1] = {0};
    for(int i = 0; i<n-1; i++){
        hash[arr[i]]++;
    }
    for(int i = 1; i<=n; i++){
        if (hash[i]==0){
            return i;
        }
    }
}


// optimal approach 1
// method 3
// TC = O(N)
// SC = O(1)
int missingNumber3(int arr[], int n){
    int sum = 0;
    for(int i = 0; i<n-1; i++){
        sum = sum + arr[i];
    }
    int sumofN = (n*(n+1))/2;
    return sumofN-sum;
}


// optimal approach 2
// method 4
// TC = O(N)
// SC = O(1)
// BUT THIS IS BETTER APPROACH THAN SUMMATION, BECAUSE IN CASE LARGE N
// LIKE 10 TO THE POWER 5 , SUM APPROACH WILL TAKE LOTS OF COMPUTAION TIME
// BUT XOR IS MORE FASTER IN LARGE N
int missingNumber4(int arr[], int n){
    int orgXor = 0;
    // for(int i = 1; i<=n; i++){
    //     orgXor = orgXor ^ i;
    // }
    // instead of this we can do this inside 2nd loop
    int newXor = 0;
    for(int i = 0; i<n-1; i++){
        newXor = newXor ^ arr[i];
        orgXor = orgXor ^ (i+1);
    }
    orgXor = orgXor ^ n;
    
    return orgXor ^ newXor;
}


int main(){

    int n;
    cout<< "Enter 1 to which element: ";
    cin>> n;

    cout<< endl;
    cout<< "Now enter " << n-1 << " elements one by one:" << endl;
    int arr[n-1];
    for(int i = 0; i<n-1; i++){
        cin>> arr[i];
    }

    // int num = missingNumber1(arr, n);
    // int num = missingNumber2(arr, n);
    // int num = missingNumber3(arr, n);
    int num = missingNumber4(arr, n);

    cout<< "missing number: " << num << endl;

    return 0;
}