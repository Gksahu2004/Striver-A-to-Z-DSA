// Union of two sorted arrays

#include<bits/stdc++.h>
using namespace std;

// brute force
// method 1
// TC = O(n1logn1 + n2logn2) + o(n1+n2)
// SC = O(N1+N2) + O(N1+N2)
vector <int> unionoftwoarray1(int arr[], int brr[], int n1, int n2){
   set<int> st;
   for(int i = 0; i<n1; i++){
    st.insert(arr[i]);
   }
   for(int i = 0; i<n2; i++){
    st.insert(brr[i]);
   }
   vector <int> vec;
   for(auto it: st){
        vec.push_back(it);
   }

   return vec;
}


// optimal
// method 2
// TC = O(N1 + N2)
// SC = O(N1 + N2)
vector <int> unionoftwoarray2(int arr[], int brr[], int n1, int n2){
    vector <int> unionarr;
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2){
        if(arr[i] <= brr[j]){
            if (unionarr.size() == 0 || arr[i] != unionarr.back()){
                unionarr.push_back(arr[i]);
            } 
            i++;
        }
        else{
            if (unionarr.size() == 0 || brr[j] != unionarr.back()) {
                unionarr.push_back(brr[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if (unionarr.size() == 0 || arr[i] != unionarr.back()){
            unionarr.push_back(arr[i]);
        } 
        i++;
    }
    while(j<n2){
        if(unionarr.size() == 0 || brr[j] != unionarr.back()){
            unionarr.push_back(brr[j]);
        }
        j++;
    }
    return unionarr;
}


// optimal approach
// intersection
vector <int> intersectionArr(int arr[], int brr[], int n1, int n2){
    vector <int> intersectionArr;
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2){
        if (arr[i] < brr[j]){
            i++;
        }
        else if(arr[i] > brr[j]){
            j++;
        }
        else{
            intersectionArr.push_back(arr[i]);
            i++;
            j++;  
        }
    }
    return intersectionArr;
}

int main(){
    int m;
    cout<< "Enter the size of array 1: ";
    cin>> m;

    cout<< "Enter all the values of array 1" << endl;
    int arr[m];
    for(int i = 0; i<m;i++){
        cin >> arr[i];
    }
    int n;
    cout<< "Enter the size of array 2: ";
    cin>> n;

    cout<< "Enter all the values of array 2" << endl;
    int brr[n];
    for(int i = 0; i<n;i++){
        cin >> brr[i];
    }

    // vector <int> temp = unionoftwoarray1(arr, brr, m, n);

    // vector <int> temp = unionoftwoarray2(arr, brr, m, n);


    vector <int> temp = intersectionArr(arr, brr, m, n);

    for(auto it: temp){
        cout<< it << " ";
    }


    return 0;
}