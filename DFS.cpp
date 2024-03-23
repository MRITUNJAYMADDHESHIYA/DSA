//depth first search
 #include<bits/stdc++.h>
 using namespace std;

//adj[]->store all the value neighbours(This declares an array of vectors. Each element of the array is a vector that stores integers.)
//vis[]->visited or not visited value
//ls->This list store the value who visited
 void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){ //if is use for ->This node have to unvisited for going in depth
            dfs(it, adj, vis, ls);
        }
    }
 }


//time=O(N)+o(2*E),space=O(N) + o(n) +O(n)
 vector<int> dfOfGraph(int n, vector<int> adj[]){
    int vis[n] = {0};
    int start = 0;

    vector<int> ls;

    dfs(start, adj, vis, ls);
    return ls;
 }



 //Note:-
//vector<vector<int>> graph(V, vector<int>(V, 0));->Matrix
//vector<bool> visited(V, false); ->array with false value
//