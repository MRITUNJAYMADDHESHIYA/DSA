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


void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//time=O(N),space=O(N)
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


//time=O(3*N),sapce=O(4*N)
vector<vector<int>> preInPost(Node* root){
    vector<int> pre, in, post;
    stack<pair<Node* , int>> st;
    st.push({root, 1});

    vector<vector<int>> result;
    if(root == NULL) return result;

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        //this is part of pre
        //increment 1 to 2
        //push the left side of side of the tree
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left !=NULL){
                st.push({it.first->left, 1});
            }
        }

        //this is part of in
        //increment 2 to 3
        //push the right side of side of the tree
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL){
                st.push({it.first->right, 1});
            }
        }

        //don't push it back again
        else{
            post.push_back(it.first->data);
        }
    }

    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    
    return result; // Return the traversals
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout<<endl;
    cout<<endl;

    vector<vector<int>> ans = preInPost(root);
    for(auto traversal : ans) {
        for(auto element : traversal) {
            cout << element << " ";
        }
        cout << endl; // Print a newline after each traversal
    }

    return 0;
}
