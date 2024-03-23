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


//time=O(n),space=O(n)
int MaxiWidth(Node* root){
    if(!root) return 0;
    int width = 0;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        int size = q.size();
        int curMin = q.front().second; //minimum index at that level

        int leftMost, rightMost;

        //for queue
        for(int i=0; i<size; i++){
            int cur_index = q.front().second - curMin; //for overflow
            Node* temp = q.front().first;
            q.pop();

            if(i == 0) leftMost = cur_index; //store the first value
            if(i == size - 1) rightMost = cur_index; // store the last value

            if(temp->left){
                q.push({temp->left, cur_index*2+1});
            }
            if(temp->right){
                q.push({temp->right, cur_index*2+2});
            }
        }
        width = max(width, rightMost - leftMost + 1);
    }
    return width;
}

int main() {

  Node* root = new Node(1);
  root -> left = new Node(3);
  root -> left -> left = new Node(5);
  root -> left -> left -> left = new Node(7);
  root -> right = new Node(2);
  root -> right -> right = new Node(4);
  root -> right -> right -> right = new Node(6);

  int maxWidth = MaxiWidth(root);
  cout << "The maximum width of the Binary Tree is " << maxWidth;

  return 0;
}