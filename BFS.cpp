//breath first search
#include<bits/stdc++.h>
using namespace std;

//sapce=O(3N),time=o(n)+O(2E)
//adj[]->>>index node that adjecent element is a vector
vector<int> bfsOfGraph(int n, vector<int> adj[]){

    int vis[n] = {0};  //arr of 0 value
    vis[0] = 1;

    queue<int> q;
    q.push(0);

    vector<int> bfs; //for finall ans
    while(!q.empty()){
        int node = q.front(); //top most element
        q.pop();
        bfs.push_back(node);

        //traverse for all its neighbours
        for(auto it: adj[node]){
            //if the neighbour has previously not been visited, 
            // store in Q and mark 1 as visited 
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans){
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i] <<" ";
    }
}

int main() 
{
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector <int> ans = bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}