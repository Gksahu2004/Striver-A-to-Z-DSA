// Longest Consecutive Sequence in an Array


#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
bool linearsearch(int arr[], int n, int x){
    for(int i = 0; i<n; i++){
        if(arr[i] == x){
            return true;
        }
    }
    return false;
}
void longestSequence1(int arr[], int n){
    int maxlength = 0;
    for(int i = 0; i<n; i++){
        int x = arr[i];
        int length = 0;
        while(linearsearch(arr, n, x) == true){
            x = x+1;
            length++;
            maxlength = max(maxlength, length);
        }
    }
    cout<< "Longest length: " << maxlength << endl;
}


// better solution
// TC = O(N x logN) + O(N)     // [SORTING + ONE LOOP]
// SC = O(1)
void longestSequence2(int arr[], int n){
    sort(arr, arr+n);

    cout<< "sorted array: ";
    for(int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }
    cout<< endl;

    cout<< "longest consecutive sequence length is: " << endl;
    int longestlength = 0;
    int length = 1;
    int lastminimum = INT_MIN;
    for(int i = 0; i<n; i++){
        cout<< i << ". ";
        if(arr[i] == lastminimum+1){
            length++;
            lastminimum = arr[i];
        }
        else if(arr[i] != lastminimum){
            lastminimum = arr[i];
            length = 1;
        }
        longestlength = max(longestlength, length);
        cout<< "length: " << length << ", longest length: " << longestlength << endl;
    }
    // cout<< longestlength << endl;
}


// optimal solution
// TC = O(N) + O(2N) = O(3N)
// SC = O(N)
void longestSequence3(int arr[], int n){
    unordered_set <int> st;
    int length = 0;
    int longestlength = 0;
    for(int i = 0; i<n; i++){
        st.insert(arr[i]);
    }
    for(auto it: st){
        if(st.find(it - 1) == st.end()){ // if previous element not found in set, then it may be a starting point of a sequence
            length = 1;
            int x = it+1;
            while(st.find(x) != st.end()){
                length++;
                x++;
            }
        }
        longestlength = max(longestlength, length);
    }
    cout<< "longest length: "<< longestlength;
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

    
    // longestSequence1(arr, n);
    // longestSequence2(arr, n);
    longestSequence3(arr, n);



    return 0;
}