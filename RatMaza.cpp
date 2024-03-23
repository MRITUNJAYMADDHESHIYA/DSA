#include<bits/stdc++.h>
using namespace std;

void findPathHelper(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string move, vector<vector<int>> & vis){
    if(i == n-1 && j == n-1){
        ans.push_back(move);
        return;
    }

    //downward
    if(i+1 < n && !vis[i+1][j] && mat[i+1][j] == 1){ //boundary +visit+ equal to 1
        vis[i][j] = 1;
        findPathHelper(i+1, j, mat, n, ans, move + 'D', vis);
        vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && mat[i][j - 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j - 1, mat, n, ans, move + 'L', vis);
      vis[i][j] = 0;
    }

    // right 
    if (j + 1 < n && !vis[i][j + 1] && mat[i][j + 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j + 1, mat, n, ans, move + 'R', vis);
      vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && mat[i - 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i - 1, j, mat, n, ans, move + 'U', vis);
      vis[i][j] = 0;
    }
}

vector<string> findPath1(vector<vector<int>> &mat, int n){
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int> (n,0));

    if(mat[0][0] == 1) findPathHelper(0, 0, mat, n, ans, "", vis);
    return ans;
}

// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
// Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).

void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
        ans.push_back(move);
        return;
    }

    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
            vis[i][j] = 1;
            solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
            vis[i][j] = 0;
        }
    }
}

vector < string > findPath2(vector < vector < int >> & m, int n) {

    vector < string > ans;
    vector < vector < int >> vis(n, vector < int > (n, 0));
    int di[] = {+1,0,0,-1};
    int dj[] = {0,-1,1,0};
    if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
    return ans;
}