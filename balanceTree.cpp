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

//time=O(N), space =O(N)
int diffHeight(Node* root){
    if(root == NULL) return 0;

    int leftHeight = diffHeight(root->left);
    if(leftHeight == -1) return -1;
    int rightHeight = diffHeight(root->right);
    if(rightHeight == -1) return -1;

    if(abs(leftHeight - rightHeight) > 1) return -1;
    return 1 + max(leftHeight, rightHeight);

}

bool balance(Node* root){
    return diffHeight(root) != -1;
}