#include<bits/stdc++.h>
using namespace std;

//time=O(N+2E)
//space=O(N)+O(N)
bool detect(int src, vector<int> adj[], int vis[]){
    vis[src] = 1;

    queue<pair<int, int>> q; //<node, parent node>
    q.push({src, -1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode: adj[node]){
            //if adjecent node is unvisited
            if(!vis[adjacentNode]){
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }

            //if adjecent node is visited
            else if(parent != adjacentNode){
                return true;
            }
        }
    }
    return false;
}


bool isCycle(int v, vector<int> adj[]){
    int vis[v] = {0};
    
    //for multiple components/graph
    for(int i=0; i<v; i++){
        if(!vis[i]){
            if(detect(i, adj, vis)) return true;
        }
    }

    return false;
}