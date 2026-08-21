// Longest subarray with given sum K(positives)


#include <bits/stdc++.h>
using namespace std;


// brute force 1
// TC = O(N^3)
int longestSubarray1(int arr[], int n, int target){
    int length = 0;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int sum = 0;
            for(int k = i; k<j; k++){
                sum = sum + arr[k];
            }
            if(sum == target){
                length = max(length, j-i);
            }
        }
    }
    return length;

}


// brute force 2 (better than brute force 1)
// TC = O(N^2)
int longestSubarray2(int arr[], int n, int target){
    int length = 0;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            if(sum == target){
                length = max(length, j-i);
                break;
            }
            else if(sum > target){
                break;
            }
            else{
                sum = sum + arr[j];
            }
        }
    }
    return length;
}


// better solution (using map)
// better solution for +ve and zero values
// ***** but optimal solution for +ve, -ve and zero values ******
// TC = O(N x logN) for ordered map
// TC = O(N x 1) for unordered best time complexity
// TC = O(N x N) = O(N^2) for unordered worst time(when collison happens) complexity
int longestSubarray3(int arr[], int n, int target){
    long long sum = 0;
    int maxlen = 0;
    map <long long, int> mpp;
    for(int i = 0; i<n; i++){
        sum = sum + arr[i];
        if(sum == target){
            maxlen = max(maxlen, i+1);
        }

        // remaining sum calculation
        long long rem = sum - target;

        // rem exists in map
        if(mpp.find(rem) != mpp.end()){
            int len = i - mpp[rem];
            maxlen = max(maxlen, len);
        }

        // rem does not exists in map
        if(mpp.find(rem) == mpp.end()){
            mpp[sum] = i;
        }
    }
    return maxlen;
}


// optimal solution (using 2 pointers) for only +ve and zero values not -ve values
// TC = O(2N) if both pointers move till N
// SC = O(1)
int longestSubarray4(int arr[], int n, int target){
    // right pointer
    int i = 0;
    // left pointer
    int j = 0;
    int sum = arr[0];
    int maxlen = 0;

    // MY CODE
    // // before while loop
    // right pointer
    // int i = 0;
    // // left pointer
    // int j = 0;
    // int sum = 0;
    // int maxlen = 0;

    while(i<n){
        while(j<=i && sum>target){
            sum = sum - arr[j];
            j++;
        }
        if(sum==target){
            maxlen = max(maxlen, i-j+1);
        }
        i++;
        if(i<n){
            sum = sum + arr[i];
        }


        // MY CODE

        // if(sum<=target){
        //     if(sum == target){
        //         maxlen = max(maxlen, i-j);
        //     }
        //     sum = sum + arr[i];
        //     i++;
        // }
        // else{
        //     sum = sum - arr[j];
        //     j++;
        // }
    }
    return maxlen;
}



int main(){
    int n;
    cout<< "Enter the size of array: ";
    cin>> n;

    int arr[n];
    cout<< "Now enter all the elements of array one by one:"<< endl;
    for(int i = 0; i<n; i++){
        cin>> arr[i];
    }

    int targetSum;
    cout<< "Now enter target sum: ";
    cin>> targetSum;

    // int length = longestSubarray1(arr, n, targetSum);
    // int length = longestSubarray2(arr, n, targetSum);
    // int length = longestSubarray3(arr, n, targetSum);
    int length = longestSubarray4(arr, n, targetSum);

    cout<< "length of the longest sub array: "<< length;

    return 0;
}