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

// if +ve numbers count > -ve numbers or -ve numbers count > +ve numbers
// TC = O(N) + O(MIN(pos, neg)) + O(left overs)
// WORST TC = O(N) + O(N) [IF ALL ARE +VE OR -VE OR SIZE OF BOTH NOT EQUAL] + O(0) = O(N) + O(N) = O(2N)
// BEST TC = O(N) + O(N/2) [IF SIZE OF NOTH POS AND NEG ARE SAME] + O(0) = O(N) + O(N/2)
// SC = O(pos) + O(neg) = O(N)
void rearrangebysign3(int arr[], int n){
    vector<int> pve;
    vector<int> nve;
    for(int i = 0; i<n ; i++){
        if(arr[i] >= 0){
            pve.push_back(arr[i]);
        }
        else{
            nve.push_back(arr[i]);
        }
    }

    int i = 0;
    int min;
    if (pve.size() <= nve.size()){
        min = pve.size();
    }
    else{
        min = nve.size();
    }
    for( ; i<min; i++){
        arr[2*i] = pve[i];
        arr[2*i+1] = nve[i];
    }

    i = min*2;
    int j = min;
    if(pve.size() >= nve.size()){
        while(i<n){  // the condition is same as while(j < pve.size())
            arr[i] = pve[j];
            i++;
            j++;
        }
    }
    else{
        while(i<n){ // the condition is same as while(j < nve.size())
            arr[i] = nve[j];
            i++;
            j++;
        }
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
    // rearrangebysign2(arr, n);
    rearrangebysign3(arr, n);

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}