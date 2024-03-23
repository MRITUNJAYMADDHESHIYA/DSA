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

//time=O(N),sapce=O(N)
bool getPath(Node* root, vector<int>& arr, int target){
    if(!root) return false;

    arr.push_back(root->data);

    if(root->data == target) return true;

    if(getPath(root->left, arr, target) || getPath(root->right, arr, target)) return true;

    arr.pop_back();
    return false;
}

// vector<int> all RootToLeaf1(Node* root, int target){
//     vector<int> arr;
//     if(root == NULL) return arr;
//     getPath(root, arr, target);
//     return arr;
// }


vector<string> allRootToLeaf2(Node* root) {
    vector<string> paths;
    if (root == NULL) {
        return paths;
    }
    // Base case
    if (root->left == NULL && root->right == NULL) {
        paths.push_back(to_string(root->data));
        return paths;
    }

    // Recursive cases for left and right subtrees
    vector<string> leftPaths = allRootToLeaf2(root->left);
    for (string &path : leftPaths) {
        paths.push_back(to_string(root->data) + " " + path);
    }

    vector<string> rightPaths = allRootToLeaf2(root->right);
    for (string &path : rightPaths) {
        paths.push_back(to_string(root->data) + " " + path);
    }
    return paths;
}


int main(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(6);
    root -> left -> right -> right = new Node(7);
    root -> right = new Node(3);

    vector<int> arr;
    bool ans;
    ans = getPath(root, arr, 7);

    for(auto it: arr){
        cout<<it<<" ";
    }
    
    return 0;
}