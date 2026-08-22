// Sort an array of 0's 1's and 2's


// brute force approach
// use any sorting algorithm
// TC = O(N x logN)
// SC = O(N) if you use merge sort


// better solution
// use three counters like int zeros, int ones and int twos
// run one loop and update those counters
// after that run a loop again but this time fill all in array
// like first all zeros, all ones then all twos
// TC = O(2N)
// SC = O(1)


// optimal solution (Dutch National Flag Algorithm)
// 0 to low-1  (0 sorted)
// low to mid-1 (1 sorted)
// mid to high (unsorted)
// high+1 to n-1 (2 sorted)
// TC = O(N)
// SC = O(1)

#include <bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n){
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else if(arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }
        else{
            cout<< "Invalid input, you have entered except 0,1 or 2"<< endl;
            return;
        }
    }
    return;
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
    
    sort012(arr, n);

    for(int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }
    cout<< endl;

    return 0;
}