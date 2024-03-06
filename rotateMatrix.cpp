#include<bits/stdc++.h>
using namespace std;

//time=O(n*n),space=O(n*n)
vector<vector<int>> rotate(vector<vector<int>> &matrix){
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int> (n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            rotated[j][n-1-i] = matrix[i][j];
        }
    }
    return rotated;
}


//Step 1: Transpose the matrix. (transposing means changing columns to rows and rows to columns)
//Step 2: Reverse each row of the matrix.
//time=O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.,space=O(1)
vector<vector<int>> rotate2(vector<vector<int>> &matrix){
    int n = matrix.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //each row of the matrix reverse
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return matrix;
}

void rotateMatrixByOne(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[m].size();

    int row = 0, col = 0; 
    int prev, curr; 
    int lastRow= n;
    int lastCol= m;
    while (row < lastRow && col < lastCol) 

    {  
        if (row + 1 == lastRow || col + 1 == lastCol)  break;   

        prev = matrix[row + 1][col]; 
        //for the first row which is in bounds
        for (int i = col; i < lastCol; i++) 
        { 
            curr = matrix[row][i]; 
            matrix[row][i] = prev; 
            prev = curr; 
        } 
        row++; 
        //for the last column which is in bounds
        for (int i = row; i < lastRow; i++) 
        { 
            curr = matrix[i][lastCol-1]; 
            matrix[i][lastCol-1] = prev; 
            prev = curr; 
        } 
        lastCol--;   
        //for the last row which is in bounds
        if (row < lastRow) 
        { 
            for (int i = lastCol-1; i >= col; i--) 
            { 
                curr = matrix[lastRow-1][i]; 
                matrix[lastRow-1][i] = prev; 
                prev = curr; 
            } 
        } 
        lastRow--; 
        //for the first row which is in bounds
        if (col < lastCol) 
        { 
            for (int i = lastRow-1; i >= row; i--) 
            { 
                curr = matrix[i][col]; 
                matrix[i][col] = prev; 
                prev = curr; 
            } 
        } 
        col++; 
    } 
 
    for (int i=0; i<4; i++) 
    { 
        for (int j=0; j<4; j++) 
          cout << matrix[i][j] << " "; 
        cout << "\n"; 
    } 
} 


int main(){
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> ans = rotate2(arr);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<< ans[i][j]<<" ";
        }
        cout<<endl;
    }
}