#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int min_index = i;
        for(int j = i+1; j<n; j++){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }

}

void bubble_sort(int arr[], int n){
    for(int i = 0; i<n; i++){
        for (int j = 0; j<n-1-i; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void bubble_sort_optimized(int arr[], int n){
    for(int i = 0; i<n; i++){
        int flag = 0;
        for (int j = 0; j<n-1-i; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}

void insertion_sort(int arr[], int n){
    for(int i = 1; i<n; i++){
        for(int j = i; j>0; j--){
            if (arr[j-1] > arr[j]){
                swap(arr[j], arr[j-1]);
                cout<< "swap" << endl;
            }
            else break;
        }
    }
}

void merge(int arr[], int low, int mid, int high){
    int i = low,j = low,k = mid+1;
    int brr[100];
    while(i<=mid && k<=high){
        if (arr[i] <= arr[k]){
            brr[j] = arr[i];
            i++;
            j++;
        }
        else{
            brr[j] = arr[k];
            k++; 
            j++;
        }
    }
    while(i<=mid){
        brr[j] = arr[i];
        i++;
        j++;
    }
    while(k<=high){
        brr[j] = arr[k];
        k++;
        j++;
    }
    for(int i = low; i<=high; i++){
        arr[i] = brr[i];
    }

}
void mergesort(int arr[], int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while(i<j){
        while(arr[i] <= pivot && i<=high) i++;
        while(arr[j] > pivot && j>=low) j--;
        if (i<j){
            swap(arr[i], arr[j]);
        } 
    }
    swap(arr[j], arr[low]);
    return j;
}
void quicksort(int arr[], int low, int high){
    if (low < high){
        int partition_idx = partition(arr, low, high);
        quicksort(arr, low, partition_idx-1);
        quicksort(arr, partition_idx+1, high);
    }
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

    // selection_sort(arr, n);

    // bubble_sort(arr, n);
    // bubble_sort_optimized(arr, n);

    // insertion_sort(arr, n);

    // mergesort(arr,0,n-1);

    quicksort(arr, 0, n-1);

    cout<< endl;
    for(int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }


    return 0;
}