// left rotate an array by d places

#include<bits/stdc++.h>
using namespace std;

// brute force
// method 1 (more TC but less SC)
void leftrotatebyd1(int arr[], int n, int d){
    vector <int> vec ;
    for(int i = 0; i<d; i++){
        vec.push_back(arr[i]);
    }
    for(int i = d; i<n; i++){
        arr[i-d] = arr[i];
    }
    for(int i = n-d; i<n; i++){
        arr[i] = vec[i-(n-d)];
    }
}

// optimal
// method 2 (less TC but more SC)
void leftrotatebyd2(int arr[], int n, int d){
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}


// right rotate by d = left rotate by (n-d)
void rightrotatebyd(int arr[], int n, int d){
    reverse(arr, arr+n-d);
    reverse(arr+n-d, arr+n);
    reverse(arr, arr+n);
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

    int d;
    cout << "Enter how many places you want to rotate: ";
    cin >> d;

    // leftrotatebyd1(arr, n, d%n);
    // leftrotatebyd2(arr, n, d%n);

    rightrotatebyd(arr, n, d%n);

    for(int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }

    return 0;
}