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

//using recursion
//time=O(N), space=O(1)+O(H)
int maxDepth(Node* root){
    if(root == NULL) return 0;

    int leftH = maxDepth(root->left);
    int rightH = maxDepth(root->right);

    return 1+max(leftH, rightH);
}


//using queue
//time=O(N), space=O(N)
int maxDepth(Node* root){
    if(root == NULL) return 0;

    queue<Node* > q;
    int level = 0;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        for(int i=0; i<size; i++){
            Node* temp = q.front();
            q.pop();

            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }

            level++;
        }
    }
    return level;
}