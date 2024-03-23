#include<bits/stdc++.h>
using namespace std;


//time=O[4*N*M]
//space=O(N*M)+O(N*M)vis+queue
int numEnclaves(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    queue<pair<int, int>> q;
    int vis[n][m] = {0};

    //for boundary
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(mat[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1; 
               }
            }
        }
    }

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        //traverses for 4 direction
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 1){
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }

    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1 && vis[i][j] ==0){
                count++;
            }
        }
    }
    return count;
}