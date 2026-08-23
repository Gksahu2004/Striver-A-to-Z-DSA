// Majority Element-I

#include <bits/stdc++.h>
using namespace std;


// brute force
// TC = O(N^2)
// SC = O(1)
int majority1(int arr[], int n){
    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = i; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > n/2) return arr[i];
    }
    return -1;
}


// BETTER SOLUTION
// using map
// TC = O(N x logN) + O(N)
// SC = O(N) if the array contains all different values
int majority2(int arr[], int n){
    int mark = n/2;
    map<int, int> mpp;
    for(int i = 0; i<n; i++){
        mpp[arr[i]]++;
    }

    int major_elem;
    for(auto it: mpp){
        if(it.second > mark){
            major_elem = it.first;
            return major_elem;
        }
    }
    return -1;
}


// optimal solution
// moore's voting algorithm
// TC = O(N) + O(N) FIRST N FOR MOORE'S ALGO 
// BUT SECOND N IS TO CHECK WHETHER THE MAJ_ELEM IS ACTUALLY A MAJORITY ELEMENT
// IF QUESTION SAID THAT THERE IS ALWAYS A MAJORITY ELEMENT 
// THEN WE DO NOT HAVE TO WRITE 2ND LOOP SO TOTAL TC WILL BE O(N)
// SC = O(1)
int majority3(int arr[], int n){
    int maj_elem = arr[0];
    int cnt = 1;
    for(int i = 1; i<n; i++){
        if(cnt == 0){
            maj_elem = arr[i];
            cnt = 1;
        }
        else if(arr[i] == maj_elem){
            cnt++;
        }
        else{
            cnt--;
        }


        // if(cnt != 0){
        //     if(arr[i] == maj_elem){
        //         cnt++;
        //     } 
        //     else{
        //         cnt--;
        //     }
        // }
        // else{
        //     maj_elem = arr[i];
        //     cnt = 1;
        // }
    }
    int count = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == maj_elem) count++;
    }
    if(count > n/2){
        return maj_elem;
    }
    return -1;
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
    
    // int major_elem = majority1(arr, n);
    // int major_elem = majority2(arr, n);
    int major_elem = majority3(arr, n);

    if(major_elem == -1){
        cout<< "there is no major element" << endl;
    }
    else cout<< "major element: "<< major_elem << endl;
    
    return 0;
}