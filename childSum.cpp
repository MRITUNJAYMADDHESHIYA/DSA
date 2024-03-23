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

//time=O(N)
void childSum(Node* root){
    if(root == NULL) return;

    //going to down
    int child = 0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;

    if(child < root->data){
        root->left->data = root->data;
        root->right->data = root->data;
    }
    else{
        root->data = child;
    }

    childSum(root->left);
    childSum(root->right);

    //up
    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) root->data = total;
}

int main() {

  Node * root = new Node(2);
  root -> left = new Node(35);
  root -> left -> left = new Node(2);
  root -> left -> right = new Node(3);
  root -> right = new Node(10);
  root -> right -> left = new Node(5);
  root -> right -> right = new Node(2);

  childSum(root);

  return 0;
}