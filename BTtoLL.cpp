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
// Node* prev = NULL;
// void flatten(Node* root){
//     static Node* prev = NULL;
//     if(root == NULL) return;

//     flatten(root->right);
//     flatten(root->left);

//     root->right = prev;
//     root->left = NULL;
//     prev = root;
// }



//time=O(N),space=O(N)
// Node* prev = NULL;
// void flatten2(Node* root){
//     static Node* prev = NULL;
//     if(root == NULL) return;

//     stack<Node*> st;
//     st.push(root);
//     while(!st.empty()){
//         Node* cur = st.top();
//         st.pop();

//         if(cur ->right != NULL) st.push(cur->right);
//         if(cur ->left != NULL) st.push(cur->left);
//         if(!st.empty()) cur->right = st.top();

//         cur->left = NULL;

//     }
// }


//time=O(N),space=O(1)
Node* prev = NULL;
void flatten3(Node* root){
    static Node* prev = NULL;

    Node* cur = root;
    while(cur != NULL){

        if(cur->left !=NULL){
            Node* prev = cur->left;

            //left right most node
            while(prev->right){
                prev = prev->right;
            }

            prev->right = cur->right; //join the left right most node to right first node
            cur->right = cur->left;
        }
        cur = cur->right;
    }
}


int main() {

  Node * root = new Node(1);
  root -> left = new Node(2);
  root -> left -> left = new Node(3);
  root -> left -> right = new Node(4);
  root -> right = new Node(5);
  root -> right -> right = new Node(6);
  root -> right -> right -> left = new Node(7);

  flatten3(root);
  while(root->right!=NULL)
  {
      cout<<root->data<<"->";
      root=root->right;
  }
cout<<root->data;
  return 0;
}