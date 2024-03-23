#include<bits/stdc++.h>
using namespace std;


//time=O(N)+O(V+2E)
//space=O(n)+O(n)
void dfs(int node, vector<int> adjLs[], int vis[]){

    vis[node] = 1;
    for(auto it: adjLs[node]){
        if(!vis[it]){
            dfs(it, adjLs, vis);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int v){
    vector<int> adjLs[v];

    //to change adjecency matrix to list
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){

            //There is a node but not self nodes considerd
            if(adj[i][j] == 1 && i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    int vis[v] = {0};
    int cnt = 0;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            cnt++;
            dfs(i, adjLs, vis);
        }
    }
    return cnt;

}