#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node* random;

    public:
    Node(int data1, Node* next1, Node* back1, Node* random1){
        data = data1;
        next = next1;
        back = back1;
        random = random1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
        random = nullptr;
    }
};
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
void print(Node* head){
    while(head != NULL){
        cout<< head->data <<" ";
        head = head-> next;
    }
    cout<< endl;
}


//time=O(2N)for hashmap O(1), space=O(N)=O(N)
Node* RandomCopy(Node* head){
    unordered_map<Node*, Node*> mpp;
    Node* temp = head;

    //inserting the node in the map
    while(temp!=NULL){
        Node* newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }

    temp = head;
    while(temp!=NULL){
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];

        temp = temp->next;
    }
    return mpp[head];
}


//time=O(N)+O(N)+o(N),space=O(N)
//1.Insert copyNode in between
//2.connect random pointer
//3.connect the next pointer(Exteract form the original nodes)
Node* RandomCopy2(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        Node* copyNode = new Node(temp->data);
        copyNode->next = temp->next; //join
        temp->next = copyNode;  //join
        temp = temp->next->next;
    }

    temp = head;
    while(temp != NULL){
        Node* copyNode = temp->next;

        if(temp->random){
            copyNode->random = temp->random->next; //join random
        }
        else{
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }

    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    temp = head;
    while(temp != NULL){
        res->next = temp->next;//join
        res = res->next;

        temp->next = temp->next->next;//join
        temp = temp->next;
    }
    return dummyNode->next;
}

