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


//time=O(N),space=O(H)
void rightV(Node* root, int level, vector<int> &ans){
    if(root == NULL) return;

    if(level == ans.size()) ans.push_back(root->data);
    rightV(root->right, level+1, ans);
    rightV(root->left, level+1, ans);
}

vector<int> rightview(Node* root){
    vector<int> ans;
    rightV(root, 0, ans);
    return ans;
}


//time=O(N),space=O(H)
void leftV(Node* root, int level, vector<int> &ans){
    if(root == NULL) return;

    if(level == ans.size()) ans.push_back(root->data);
    leftV(root->left, level+1, ans);
    leftV(root->right, level+1, ans);
}

vector<int> rightview(Node* root){
    vector<int> ans;
    leftV(root, 0, ans);
    return ans;
}