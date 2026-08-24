// Rearrange Array Elements by Sign
// arrange +ve and -ve numbers alternately like + - + - + -
// there will always be same amount of +ve and -ve


#include<bits/stdc++.h>
using namespace std;

// brute force
// TC = O(N) + O(N/2)
// SC = O(N/2) + O(N/2) = O(N)
void rearrangebysign1(int arr[], int n){
    int positive[n/2];
    int negative[n/2];
    int pve = 0;
    int nve = 0;
    for(int i = 0; i<n; i++){
        if (arr[i] >= 0){
            positive[pve] = arr[i];
            pve++;
        }
        else{
            negative[nve] = arr[i];
            nve++;
        }
    }
    for(int i = 0; i<n/2; i++){
        arr[2*i] = positive[i];
        arr[2*i+1] = negative[i];
    }
}


// optimal approach
// TC = O(N)
// SC = O(N)
// NOT A HUGE IMPROVEMENT BUT OKAY
void rearrangebysign2(int arr[], int n){
    int ans[n];
    int pve = 0;
    int nve = 1;
    for(int i = 0; i<n; i++){
        if(arr[i]>=0){
            ans[pve] = arr[i];
            pve += 2;
        }
        else{
            ans[nve] = arr[i];
            nve += 2;
        }
    }
    for(int i = 0; i<n; i++){
        cout<< ans[i] << " ";
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

    // rearrangebysign1(arr, n);
    rearrangebysign2(arr, n);

    // for(int i = 0; i<n; i++){
    //     cout << arr[i] << " ";
    // }

    return 0;
}