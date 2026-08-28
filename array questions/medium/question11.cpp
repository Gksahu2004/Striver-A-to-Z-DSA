// Set Matrix Zeroes

#include<bits/stdc++.h>
using namespace std;

// brute force
// TC = O(M*N*(M+N)) + O(M*N) = O(N^3)  // ALMOST
// SC = O(1)
void markrow(int matrix[][100], int i, int column){ // mark row -1 of that if not 0
    for(int j = 0; j<column; j++){
        if (matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
void markcolumn(int matrix[][100], int j, int row){ // mark column -1 of that if not 0
    for(int i = 0; i<row; i++){
        if (matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
void setmatrixzeros1(int matrix[][100], int row, int column){
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            if (matrix[i][j] == 0){
                markrow(matrix, i, column);
                markcolumn(matrix, j, row);
            }
        }
    }
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            if (matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
}

// better solution
// TC = O(M*N) + O(M*N) = O(2*M*N)
// SC = O(M) + O(N) = O(2*N)  // ALMOST
void setmatrixzeros2(int matrix[][100], int row, int column){
    int rowMatrix[row];
    int colMatrix[column];
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            if (matrix[i][j] == 0){
                rowMatrix[i] = 0;
                colMatrix[j] = 0;
            }
        }
    }
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            if(rowMatrix[i] == 0 || colMatrix[j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

}


// optimal solution
// TC = O(M*N) + O(M*N) = O(2*M*N)
// SC = O(1)
void setmatrixzeros3(int matrix[][100], int row, int column){
    int col0;
    // rowMatrix: [...][0] to [...][0]
    // colMatrix: [0][...] to [0][...]

    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            if (matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j!=0){
                    matrix[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i = 1; i<row; i++){
        for(int j = 1; j<column; j++){
            if(matrix[i][0] == 0 || matrix[0][i] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if(matrix[0][0] == 0){
        for(int j = 0; j<column; j++){
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i = 0; i<row; i++){
            matrix[i][0] = 0;
        }
    }
}

int main(){
    int row;
    int column;
    cout<< "Enter no of rows: ";
    cin>> row;
    cout<< endl;
    cout<< "Enter no of columns: ";
    cin>> column;
    cout<< endl;

    cout<< "Now enter all values of matrix one by one:" << endl;
    int matrix[100][100];
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            cin>> matrix[i][j];
        }
    }

    // setmatrixzeros1(matrix, row, column);
    // setmatrixzeros2(matrix, row, column);
    setmatrixzeros3(matrix, row, column);


    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            cout<< matrix[i][j] << " ";
        }
        cout<< endl;
    }
    

    return 0;
}