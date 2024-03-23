#include<bits/stdc++.h>
using namespace std;

    // Following is the class structure of the Node class:

    // template <typename T>
    // class Node
    // { 
    // public:
    //     T data;                //T is for all datatype
    //     Node<T> *next;
    //     Node()
    //     {
    //         this->data = 0;
    //         this->next = NULL;
    //     }
    //     Node(T data)
    //     {
    //         this->data = data;
    //         this->next = NULL;
    //     }
    //     Node(T data, T* next)
    //     {
    //         this->data = data;
    //         this->next = next;
    //     }
    // };

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

//Array to linkedlist
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


int length(Node *head){
	int count = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}


int searchInLinkedList(Node* head, int k) {
    Node* temp = head;
    while(temp){
        if(temp->data == k){return 1;}
        temp = temp->next;
    }
    return 0;
}



