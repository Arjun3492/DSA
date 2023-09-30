// Set Matrix Zero
// Problem Statement: Given a matrix if an element in the matrix is 0 
// then you will have to set its entire column and row to 0 and then return the matrix.


//BRUTE FORCE APPROACH
//Traverse through the entire 2D matrix then whenever we encounter 0 ,
//mark the corresponding row /col elements to -1 where element !=0
//repeat the above step for each 0 encounter
//lastly set all -1 to 0
void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

//BETTER APPROACH
//Use 2 extra arrays one for row and one for col to mark the row/col to be turned to 0


#include <bits/stdc++.h>


vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
 vector<int> rowCheck(n,0);
 vector<int> colCheck(m,0);

 for(int i =0;i<n;i++){
   for(int j=0;j<m;j++){
     if(matrix[i][j]==0){
       rowCheck[i]=1;
       colCheck[j]=1;
     }
   }
 }
 for(int i =0;i<n;i++){
   for(int j=0;j<m;j++){
     if(rowCheck[i]==1||colCheck[j]==1){
       matrix[i][j]=0;
     }
   }
 }

 return matrix;
}
