 #include<bits/stdc++.h>
 using namespace std;

int orangesRotting(vector<vector<int>> &matrix){
    if(matrix.empty()) return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    queue<pair<pair<int , int>, int>> q; //{{r,c}, t}
    vector<vector<int>> vis;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }

    int tm = 0;
    int drow[] = {-1, 0, +1, 0};//up->right->down->left
    int dcol[] = {0, 1, 0, -1};

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && vis[nrow][ncol] != 2 && matrix[nrow][ncol] == 1){
                q.push({{nrow, ncol}, t+1});
                vis[nrow][ncol] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] != 2 && matrix[i][j] == 1){
                return -1;
            }
        }
    }
    return tm;
}