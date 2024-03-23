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

//time=o(N),space=O(N)
Node* LowestCommonAncestor(Node* root, Node* a, Node* b){
    //base case
    if(root == NULL || root == a || root == b){
        return root;
    }

    Node* left = LowestCommonAncestor(root->left, a, b);
    Node* right = LowestCommonAncestor(root->right, a, b);

    if(left == NULL){
        return right;
    }
    else if(right == NULL){
        return left;
    }
    else{
        return root; //if both are not NULL, then this is our result
    }

}
