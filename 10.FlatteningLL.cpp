#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node* child;

    public:
    Node(int data1, Node* next1, Node* back1, Node* child1){
        data = data1;
        next = next1;
        back = back1;
        child = child1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
        child = nullptr;
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

Node* ConvertedArray(vector<int> &arr){
    if(arr.size() == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i=0; i<arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        temp->child = newNode;
        temp = temp->child;
    }
    return head;
}

//time=O(N*M)+ O(X*logX) +  O(N*M),space=O(2*N*M)
Node* FlatteningLL1(Node* head){
    vector<int> arr;
    Node* temp = head;

    while(temp != NULL){
        Node* t2 = temp; //for verticle
        while(t2 != NULL){
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());
    head = ConvertedArray(arr);
}

Node* merge2list(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->next;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child; 
        }
        res->next = NULL;
    }

    if(list1){
        res->child = list1;
    }
    else{
        res->child = list2;
    }
    return dummyNode->child;
}

Node* flattenLL(Node* head){
    if(head == NULL || head->next ==NULL){
        return head;
    }

    head->next = flattenLL(head->next);
    head = merge2list(head, head->next);
    return head;
}