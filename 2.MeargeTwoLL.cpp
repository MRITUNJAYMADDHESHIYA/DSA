#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

//Searching for head
Node* constructLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

//printing
void print(Node* head){
    while(head != NULL){
        cout<< head->data <<" ";
        head = head-> next;
    }
    cout<< endl;
}


//time=O(N1)+O(N2)+O(N*logN)+O(N)
//space=O(n)+o(n)
Node* merge1(Node* head1, Node* head2){
    vector<int> arr;
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != NULL){
        arr.push_back(temp1->data);
        temp1 = temp1->next;
    }

    while(temp2 != NULL){
        arr.push_back(temp2->data);
        temp2 = temp2->next;
    }

    sort(arr.begin(), arr.end());

    Node* head = constructLL(arr);
    return head;
}


//time=o(N1+N2),Space=o(1)
Node* merge2(Node* head1, Node* head2){
    Node* h1 = head1;
    Node* h2 = head2;

    Node* dNode = new Node(-1);
    Node* temp = dNode;

    while(h1 != NULL && h2 != NULL){
        if(h1->data < h2->data){
            temp->next = h1;
            temp = h1;
            h1 = h1->next;
        }
        else{
            temp->next = h2;
            temp = h2;
            h2 = h2->next;
        }
    }
    if(h1) temp->next = h1;
    else temp->next = h2;
    return dNode->next;
}

int main(){
    vector<int> arr1 = {4,5,6,7};
    vector<int> arr2 = {1,2,3,4};

    Node* head1 = constructLL(arr1);
    Node* head2 = constructLL(arr2);

    Node* head = merge2(head1, head2);
    print(head);
    return 0;
}