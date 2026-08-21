// Two Sum Problem
// two varities like return yes/no and return index of both integer

#include <bits/stdc++.h>
using namespace std;

// brute force solution
// TC = O(N^2)
// SC = O(1)
pair <int, int> twosum1(int arr[], int n, int target){
    pair <int,int> p;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n-1; j++){ // instead of j=0 and j<n
            // if(i == j) continue; // then we can skip this
            int sum = 0;
            sum = sum + arr[i] + arr[j];
            if(sum == target){
                p.first = i;
                p.second = j;
                return p;
            }
        }
    }
}

// better solution (using map)
// *** FOR VARIETY 2 BETTER SOLUTION IS THE MOST OPTIMAL ONE ***
// TC = O(N x logN) for ordered map
// TC = O(N x 1) for unordered map (best tc)
// TC = O(N x N) for unordered map (worst tc)
// SC = O(N) for map
pair <int, int> twosum2(int arr[], int n, int target){
    pair<int, int> p;
    map<int, int> mpp;
    for(int i = 0; i<n; i++){
        int rem = target - arr[i];
        if(mpp.find(rem) != mpp.end()){
            p.first = mpp[rem];
            p.second = i;
            return p;
        }
        mpp[arr[i]] = i;
    }
    return {-1, -1};
}


// optimal solution (this is not optimal for variety 2 as after sorting our indexes get lost)
// TC = O(N x logN) + O(N)
// SC = O(1)
pair <int, int> twosum3(int arr[], int n, int target){
    sort(arr, arr+n);  // O(N x logN)
    int left = 0;
    int right = n-1;
    int sum = 0;
    pair<int, int> p;
    while(left<right){  // O(N)
        sum = arr[left] + arr[right];
        if(sum < target) left++;
        else if(sum > target) right--;
        else{
            p.first = left;
            p.second = right;
            return p;
        }
    }
    return {-1, -1};
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

    // pair<int, int> p = twosum1(arr, n, targetSum);
    // pair<int, int> p = twosum2(arr, n, targetSum);
    pair<int, int> p = twosum3(arr, n, targetSum);
    
    cout<< "indexes are: " << "(" << p.first << ", "<< p.second<< ")"<<endl;

    return 0;
}