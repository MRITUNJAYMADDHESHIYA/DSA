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


//time=O(H) + O(H) + O(N) which is ≈ O(N)
//sapce=O(N)
bool isLeaf(Node* root){
    return !root->left && !root->right;
}

void addLeftboundary(Node* root, vector<int> &ans){
    Node* temp = root->left;
    while(temp){
        if(!isLeaf(temp)) ans.push_back(temp->data);//if node is not leaf
        if(temp->left) temp = temp->left; //going to left
        else temp = temp->right;  //if left not exits the going to right
    }
}

void addRightBoundary(Node* root, vector<int> &ans){
    Node* temp = root->right;
    vector<int> ds;  //store the node value then reverse the value and add in ans
    while(temp){
        if(!isLeaf(temp)) ds.push_back(temp->data);
        if(temp->right) temp = temp->right;
        else temp = temp->left;
    }
    //reverse and add into the ans
    for(int i = ds.size() - 1; i>=0; i--){
        ans.push_back(ds[i]);
    }
}

//simple inorder 
void addLeaves(Node* root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, ans);
    if(root->right) addLeaves(root->right, ans);
}

vector<int> printBoundary(Node* root){
    vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);

    addLeftboundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
    return ans;
}

