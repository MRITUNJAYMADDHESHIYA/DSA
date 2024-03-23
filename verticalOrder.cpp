#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//time=O(N*logN*logN*logN),space=O(n)
vector<vector<int>> findVertical(Node* root){
    map<int, map<int, multiset<int>>> nodes; //vetrical, level, nodes
    queue<pair<Node* ,pair<int, int>>> todo; //node, vertical, level

    todo.push({root, {0, 0}}); //Intital value

    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();

        Node* temp = p.first;  //node from queue
        int x = p.second.first; //vertical
        int y = p.second.second; //level

        //This calls the insert method on the set (or multiset) located at position [x][y]
        nodes[x][y].insert(temp->data); //inserting to multiset

        if(temp -> left){
            todo.push({temp->left, {x-1, y+1}});
        }
        if(temp->right){
            todo.push({temp->right, {x+1, y+1}});
        }
    }

    vector<vector<int>> ans;
    for(auto p: nodes){
        vector<int> col;
        for(auto q: p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(10);
    root -> left -> left -> right = new Node(5);
    root -> left -> left -> right -> right = new Node(6);
    root -> right = new Node(3);
    root -> right -> left = new Node(9);
    root -> right -> right = new Node(10);

    vector<vector<int>> ans;
    ans = findVertical(root);
    for(auto vertical: ans){
        for(auto nodeValue: vertical){
            cout<< nodeValue <<" ";
        }
        cout<<endl;
    }
    return 0;
}