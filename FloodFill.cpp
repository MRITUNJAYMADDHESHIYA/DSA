#include<bits/stdc++.h>
using namespace std;

//time=O(N*M*4)
//sapce=O(N*M)+O(N*M) //MATRIX+RECURSION
void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int deltRow[], int deltCol[], int initialColor){
    ans[row][col] = newColor;

    int n = image.size();
    int m = image[0].size();

    for(int i=0; i<4; i++){
        int nrow = row + deltRow[i];
        int ncol = col + deltCol[i];

        //check for valid 
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == initialColor && ans[nrow][ncol] != newColor){
            dfs(nrow, ncol, ans, image, newColor, deltRow, deltCol, initialColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor){
    int initialColor = image[sr][sc];
    vector<vector<int>> ans = image;

    int deltRow[] = {-1,0,+1,0};
    int deltCol[] = {0,+1,0,-1};
    dfs(sr, sc, ans, image, newColor, deltRow, deltCol, initialColor);
    return ans;
}