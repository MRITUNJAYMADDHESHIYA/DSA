#include<bits/stdc++.h>
using namespace std;

bool isSafe1(int row, int col, vector<string> &board, int n){
    //upper diagonal left
    int duprow = row;
    int dupcol = col;
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    //left
    col = dupcol;
    row = duprow;
    while(col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }

    //lower diagonal left
    col = dupcol;
    row = duprow;
    while(row < n && col >= 0){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++){
        if(isSafe1(row, col, board, n)){
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
//time=O(N!*N),space=O(N*N)
vector<vector<string>> solveQueen1(int n){
    vector<vector<string>> ans;
    vector<string> board(n); 

    //fill with . character
    string s(n, '.');
    for(int i=0; i<n; i++){
        board[i] = s;
    }

    solve(0, board, ans, n);
    return ans;
}


void slove2(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++){
        if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n-1 + col -row] == 0){
            
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row+col] = 1;
            upperDiagonal[n-1 + col - row] = 1;

            slove2(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1 + col - row] = 0;
        }
    }
}
vector<vector<string>> solveQueen2(int n){
    vector<vector<string>> ans;
    vector<string> board(n); 

    //fill with . character
    string s(n, '.');
    for(int i=0; i<n; i++){
        board[i] = s;
    }

    vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
    slove2(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
}


int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  vector < vector < string >> ans = solveQueen2(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}