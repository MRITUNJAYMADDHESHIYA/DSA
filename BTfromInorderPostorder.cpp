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

//time=O(N)*log(n),space=O(N)
Node* buidBTHelp(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &mpp){
    if(ps>pe || is>ie) return NULL;
    
    Node* root = new Node(postorder[pe]);
    int inRoot = mpp[postorder[pe]]; //serching in the map for root
    int numsLeft = inRoot - is;  //numbers in the left

    //recursion
    root->left = buidBTHelp(inorder, is, inRoot-1, postorder, ps, ps+numsLeft-1, mpp);
    root->right = buidBTHelp(inorder, inRoot+1, ie, postorder, ps+numsLeft, pe-1, mpp);

    return root;
}

Node* buidBT(vector<int> &inorder, vector<int> &postorder){
    if(inorder.size() != postorder.size()) return NULL;

    map<int, int> mpp;
    for(int i=0; i<inorder.size(); i++){
        mpp[inorder[i]] = i;
    }

    return buidBTHelp(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mpp);
}