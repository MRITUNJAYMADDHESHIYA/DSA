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

int PathSum(Node* root, int &maxi){
    if(root == NULL) return 0;

    int left = max(0, PathSum(root->left, maxi));  //negative
    int right = max(0, PathSum(root->right, maxi));  //negative
    maxi = max(maxi, left + right + root->data);
    return max(left, right) + root->data;
}
int maxPathSum(Node* root){
    int maxi = INT_MIN;
    PathSum(root, maxi);
    return maxi;
}


// bool targetSum1(Node* root, int target){
//     if(root == NULL )return false;

//     stack<Node* > path;
//     stack<int> sumPath;

//     path.push(root);
//     sumPath.push(root->data);

//     while(!path.empty()){
//         Node* temp = path.pop();
//         int tempVal = sumPath.pop();
        
//     }
// }

bool targetSum2(Node* root, int targetSum){
    if(root == NULL){
        return false;
    }

    if(root->left == NULL  && root->right == NULL){
        return targetSum == root->data;
    }

    bool left_sum = targetSum2(root->left, targetSum - root->data);
    bool right_sum = targetSum2(root->right, targetSum - root->data);

    return left_sum || right_sum;
}