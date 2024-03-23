#include<bits/stdc++.h>
using namespace std;


//time=O(N*M +4*N*M)
//space=O(N*M + N*M + N*M) visited+dist+queue
vector<vector<int>> nearest(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<int>> dist(n, vector<int>(m,0));

    queue<pair<pair<int, int>, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){ 

            if(matrix[i][j]==1){
                q.push({{i,j}, 0});
                vis[i][j] =1;
            }
            else{
                //mark unvisited
                vis[i][j] = 0;
            }
        }
    }

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;

        q.pop();
        dist[row][col] = steps;

        //for 4 neighbours
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            //chech for valid unvisited cell
            if(nrow>=0 && nrow<n && ncol >=0 && ncol<m  && vis[nrow][ncol] == 0){
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps +1});
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> matrix{{0,1,1,0},{1,1,0,0},{0,0,1,1}};
    vector<vector<int>> ans = nearest(matrix);

    for(auto it: ans){
        for(auto j: it){
            cout<< j << " ";
        }
        cout<< " \n";
    }

    return 0;
}