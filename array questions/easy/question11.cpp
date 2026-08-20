// Maximum Consecutive Ones


#include<bits/stdc++.h>
using namespace std;


// optimal approach
int maxConsOnes(int arr[], int n){
    int maxCount = 0, count = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == 1) count++;
        else{
            if(count>maxCount) maxCount = count;
            count = 0;
        }
    }
    return maxCount;
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

    int count = maxConsOnes(arr, n);

    cout<< "maximum consecutive ones: " << count << endl;

    return 0;
}