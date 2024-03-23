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


//time=O(N), space=O(N)
vector<vector<int>> level(Node* root){
    queue<Node*> q;
    vector<vector<int>> ans;

    if(root == NULL) return ans;

    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        //loop is for pop the all the value at the same level
        for(int i=0; i<size; i++){
            Node* temp = q.front();
            q.pop();

            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }

            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}


//time=O(N),space=O(N)
vector<vector<int>> zigzaglevel(Node* root){
    vector<vector<int>> ans;
    queue<Node*> q;

    if(root == NULL) return ans;

    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);

        for(int i=0; i<size; i++){
            Node* temp = q.front();
            q.pop();

            int index = (leftToRight) ? i : (size -1 - i); //find position to fill nodes at the same level 
            level[index] = temp->data; //after the define the position insert into the level

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

        //after this level
        leftToRight = !leftToRight;
        ans.push_back(level);
    }
    return ans;
}