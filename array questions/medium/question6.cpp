// Stock Buy and Sell

#include<bits/stdc++.h>
using namespace std;


// here arr represents prices array
// TC = O(N)
// SC = O(1)
void buyandsellstocks(int arr[], int n){
    int ansprofit = 0;
    int ansbuy = -1;
    int anssell = -1;
    int minimal = arr[0];
    for(int i = 1; i<n; i++){
        int sell = arr[i];
        int profit = sell - minimal;
        if (profit > ansprofit){
            ansprofit = profit;
            ansbuy = minimal;
            anssell = sell;
        }
        if(arr[i] < minimal){
            minimal = arr[i];
        }
    }
    cout<< "buy: " << ansbuy << ", sell: " << anssell << endl;
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

    buyandsellstocks(arr, n);

    return 0;
}