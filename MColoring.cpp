#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<int> & col, vector<vector<int>> &graph, int n, int color){
    for(int k=0; k<n; k++){
        if(k != node && graph[k][node] == 1 && col[k] == color){
            return false;
        }
    }
    return true;
}

bool slove(int node, vector<int> &col, int m, int N, vector<vector<int>> &graph){
    if(node == N){
        return true;
    }

    for(int i=1; i<= m; i++){  //this loop try 1 to m color on a node
        if(isSafe(node, col, graph, N, i)){
            col[node] = i;
            if(slove(node+1, col, m, N, graph)) return true;
            col[node] = 0; //we have to remove the color
        }
    }
    return false;
}


//time=O(N^M),space=O(N)
//m->color, N->Nodes
bool graphColor(vector<vector<int>> &graph, int m, int N){
    vector<int> col(N, 0); //Initialize the vector with 0 value

    if(slove(0, col, m, N, graph)) return true;
    return false;
}

int main() {
  int N = 4;
  int m = 3;

  // Initialize the graph with N rows and each row having N elements initialized to 0
  vector<vector<int>> graph(N, vector<int>(N, 0));

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphColor(graph, m, N);
}