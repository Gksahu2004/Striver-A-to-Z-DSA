// Rotate matrix by 90 degrees


#include<bits/stdc++.h>
using namespace std;

// brute force solution
void rotateby90Brute(int matrix[][100], int row, int column){
    int ans[row][column];

    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            cin>> matrix[i][j];
        }
    }
}


// optimal solution
void rotateby90Optimal(int matrix[][100], int row, int column){
    
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

    cout<< "Now enter all elements of matrix row by row: " << endl;
    int matrix[100][100];
    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            cin>> matrix[i][j];
        }
    }

    rotateby90Brute(matrix, row, column);
    // rotateby90Optimal(matrix, row, column);

    for(int i = 0; i<row; i++){
        for(int j = 0; j<column; j++){
            cout<< matrix[i][j] << " ";
        }
        cout<< endl;
    }


    return 0;
}