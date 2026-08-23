// Kadane's Algorithm

#include<bits/stdc++.h>
using namespace std;

// brute force
// TC = O(N^3)
// SC = O(1)
int maxsumsubarray1(int arr[], int n){
    int maxsum = INT_MIN;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int sum = 0;
            for(int k = i; k<=j; k++){
                sum = sum + arr[k];
            }
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

// better solution
// TC = O(N^2)
// SC = O(1)
int maxsumsubarray2(int arr[], int n){
    int maxsum = INT_MIN;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum = sum + arr[j];
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

// optimal solution
// kadane's algorithm
// TC = O(N)
// SC = O(1)
int maxsumsubarray3(int arr[], int n){
    int maxsum = INT_MIN;
    int sum = 0;

    // these two are indexes of sub array with max sum
    int start = -1;
    int ansstart = -1;
    int ansend = -1;

    for(int i = 0; i<n; i++){
        if(sum == 0){
            // whenever sum is zero, it means a new subarray is just started
            // so we keep the starting index otherwise we can not retrieve it after moving a head
            start = i;
        }
        sum = sum + arr[i];

        if(sum>maxsum){
            maxsum = sum;
            ansstart = start;
            ansend = i; // bacause at this index a new max sum is happened
        }

        // if sum is negative then make it to zero
        // otherwise it will more negative further
        if(sum<0){
            sum = 0;
        }
    }

    // printing sub array with maximum sum
    for(int i = ansstart; i<=ansend; i++){
        cout<< arr[i] << " ";
    }
    return maxsum;
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

    // int maxsum = maxsumsubarray1(arr, n);
    int maxsum = maxsumsubarray2(arr, n);
    // int maxsum = maxsumsubarray3(arr, n);

    cout<< "maximum sum = "<< maxsum<< endl;

    return 0;
}