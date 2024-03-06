#include<bits/stdc++.h>
using namespace std;


void markeRow(vector<vector<int>> &matrix, int i){
    int m = matrix[0].size();

    for(int j=0; j<m; j++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

void markeCol(vector<vector<int>> &matrix, int i){
    int n = matrix.size();

    for(int j=0; j<n; j++){
        if(matrix[j][i] != 0){
            matrix[j][i] = -1;
        }
    }
}

//time=O((N*M)*(N + M)) + O(N*M),space=o(1)
vector<vector<int>> zeroMatrix1(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

     // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                markeRow(matrix, i);
                markeCol(matrix, j);
            }
        }
    }

     // Finally, mark all -1 as 0:
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
     }
     return matrix;
}

//time=O(2*n*m),space=O(n)+o(m)
vector<vector<int>> zeroMatrix2(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    int row[n] = {0}; //row array
    int col[m] = {0}; //col array

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                row[i] = 1; //mark ith index of row with 1
                col[j] = 1; //mark jth index of col with 1
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

//time=O(2*(N*M)),space=o(1)
vector<vector<int>> zeroMatrix3(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> ans = zeroMatrix2(matrix);

    for(auto it: ans){
        for(auto element: it){
            cout<< element << " ";
        }
        cout<<endl;
    }
    return 0;
}

