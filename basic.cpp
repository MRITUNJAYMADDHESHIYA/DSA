#include<iostream>
#include<bits/stdc++.h>
using namespace std;

////storing in the matrix
// int main(){
//     int n,m;
//     cin>> n >> m;

//     //graph(space used m*m)
//     int adj[n+1][m+1];
//     for(int i=0; i<m; i++){
//         int u ,v;
//         cin >> u >> v;
//         adj[u][v] == 1;
//         adj[v][u] == 1;
//     }
//     return 0;
// }


//storing in the list
int main(){
    int n, m;
    cin >> n >> m;

    //sapce = O(2*E)
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin>> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;

}