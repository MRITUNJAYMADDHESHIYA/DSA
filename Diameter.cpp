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


//time=O(N), space=o(1) + O(H) 
int height(Node* root, int &diameter){
    if(!root) return 0;

    int leftH = height(root->left, diameter);
    int rightH = height(root->right, diameter);

    diameter = max(diameter, leftH + rightH);
    return 1 + max(leftH, rightH);
}

int diameter(Node* root){
    int diam = 0;
    height(root, diam);
    return diam;
}