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
Node* buidTreefunction(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> inMap){
    if(preStart > preEnd || inStart > inEnd) return NULL;

    Node* root = new Node(preorder[preStart]); //pick the root from preorder

    int inRoot = inMap[root->data]; //searching in map for inorder
    int numsLeft = inRoot - inStart; // no of nodes in left

    root->left = buidTreefunction(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buidTreefunction(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

 
Node* buidTree(vector<int> &preorder, vector<int> &inorder){
    map<int, int> inMap;  //for searching in inorder

    for(int i=0; i<inorder.size(); i++){
        inMap[inorder[i]] = i;
    }

    Node* root = buidTreefunction(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size()-1, inMap);
    return root;
}

int main(){
    vector<int> preorder = {10,20,40,50,30,60};
    vector<int> inorder = {40,20,50,10,60,30};
    Node* root = buidTree(preorder, inorder);
    return 0;
}


// class Solution {
// public:
// TreeNode* constructTree(vector < int > & preorder, int preStart, int preEnd, vector 
//  < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
//   if (preStart > preEnd || inStart > inEnd) return NULL;

//   TreeNode* root = new TreeNode(preorder[preStart]);
//   int elem = mp[root -> val];
//   int nElem = elem - inStart;

//   root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,
//   inStart, elem - 1, mp);
//   root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, 
//   elem + 1, inEnd, mp);

//   return root;
// }

// TreeNode* buildTree(vector < int > & preorder, vector < int > & inorder) {
//   int preStart = 0, preEnd = preorder.size() - 1;
//   int inStart = 0, inEnd = inorder.size() - 1;

//   map < int, int > mp;
//   for (int i = inStart; i <= inEnd; i++) {
//     mp[inorder[i]] = i;
//   }

//   return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
// }
// };