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


//time=O(N),space=O(N)
vector<int> topView(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> mpp;  //line and node value
    queue<pair<Node*, int>> q; //node ans line

    q.push({root, 0});

    while(!q.empty()){
        //get the top most Node
        auto it = q.front();
        q.pop();

        Node* node = it.first;  //node
        int line = it.second;  //line number

        //check the line is present or not then put the value
        if(mpp.find(line) == mpp.end()) mpp[line] = node->data;

        if(node->left != NULL){
            q.push({node->left, line-1});
        }

        if(node->right != NULL){
            q.push({node->right, line+1});
        }
    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}

//time=O(N),space=O(N)
vector<int> BottomView(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> mpp;  //line and node value
    queue<pair<Node*, int>> q; //node ans line

    q.push({root, 0});

    while(!q.empty()){
        //get the top most Node
        auto it = q.front();
        q.pop();

        Node* node = it.first;  //node
        int line = it.second;  //line number
        mpp[line] = node->data;  //value of the node at that line


        if(node->left != NULL){
            q.push({node->left, line-1});
        }

        if(node->right != NULL){
            q.push({node->right, line+1});
        }
    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }
    return ans;
}