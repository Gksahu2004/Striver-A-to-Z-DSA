// Print the matrix in spiral manner


#include<bits/stdc++.h>
using namespace std;


// only one solution exist for it
// TC = O(M*N)
// SC = O(M*N) IF STORED IN A RESULTANT VECTOR ELSE O(1)
void spiralTraversalMatrix(int matrix[][100], int row, int col){
    int left = 0;
    int right = col-1;
    int top = 0;
    int down = row-1;

    while(left<=right && top<=down){
        for(int j = left; j<=right; j++){
            cout<< matrix[top][j] << " ";
        }
        top++;
        for(int i = top; i<=down; i++){
            cout<< matrix[i][right] << " ";
        }
        right--;
        if (top<=down){
            for(int j = right; j>=left; j--){
                cout<< matrix[down][j] << " ";
            }
            down--;
        }
        if (left<=right){
            for(int i = down; i>=top; i--){
                cout<< matrix[i][left] << " ";
            }
            left++;
        }
    }
}

int main(){
    int row, col;
    cout<< "Enter no of rows and columns in the matrix: ";
    cin>> row >> col;

    int matrix[100][100];
    cout<< "Enter all values of matrix one by one: " << endl;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cin>> matrix[i][j];
        }
    }

    cout<< endl;

    spiralTraversalMatrix(matrix, row, col);


    return 0;
}