// Rotate matrix by 90 degrees


#include<bits/stdc++.h>
using namespace std;

// brute force solution
// TC = O(N^2)
// SC = O(N^2)
void rotateby90Brute(int matrix[][100], int n){
    int ans[n][n];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            ans[j][n-1-i] = matrix[i][j];
        }
    }

    // just copying elements from ans matrix to our matrix
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            matrix[i][j] = ans[i][j];
        }
    }

}


// optimal solution
// TC = O(N/2 * N/2) + O(N * N/2)
// SC = O(1)
void rotateby90Optimal(int matrix[][100], int n){
    // transpose
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // row wise reverse
    for(int i = 0; i<n; i++){
        reverse(matrix[i], matrix[i]+n);
    }
}



int main(){
    int n;
    cout<< "Enter the size of matrix: ";
    cin>> n;
    cout<< endl;

    cout<< "Now enter all elements of matrix row by row: " << endl;
    int matrix[100][100];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>> matrix[i][j];
        }
    }

    // rotateby90Brute(matrix, n);
    rotateby90Optimal(matrix, n);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<< matrix[i][j] << " ";
        }
        cout<< endl;
    }


    return 0;
}