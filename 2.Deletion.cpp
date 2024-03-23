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

//remove head
Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head-> next;
    delete temp;
    return head;
}

//remove tail
Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr; //we have to remove the joint 
    return head;
}

//For Kth element
Node* removeK(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    Node* temp = head;
    Node* previous = NULL;
    while(temp != NULL){
        count++;
        if(count == k){
            previous->next = previous->next->next;
            free(temp);
            break;
        }
        previous = temp;
        temp = temp->next;
    }
    return head;
}

//For element
Node* removeEl(Node* head, int ele){
    if(head == NULL) return head;
    if(head->data == ele){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* previous = NULL;
    while(temp != NULL){
        if(temp->data == ele){
            previous->next = previous->next->next;
            free(temp);
            break;
        }
        previous = temp;
        temp = temp->next;
    }
    return head;
}


//Important
//Delete Node In A Linked List
//timeO(1)
Node* deleteNode(Node* node) {
    if (node != nullptr && node->next != nullptr) {
        Node* nextNode = node->next;
        node->data = nextNode->data;
        node->next = nextNode->next;
        delete nextNode;
    }
}


int main(){
    vector<int> arr = {12,5,6,4,9};
    Node* head = constructLL(arr);
    //head = removeHead(head);
    //head = removeTail(head);
    // head = removeK(head,3);
    head = removeEl(head,4);
    print(head);
}