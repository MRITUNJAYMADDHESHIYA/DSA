#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
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

//time=o(2N)
//space=o(1)
Node* findNthNode(Node* temp, int k){
    int count = 1;
    while(temp != NULL){
        if(count == k) return temp;
        count++;
        temp = temp->next;
    }
    return temp;
}

Node* RotateLL(Node* head, int k){
    if(head == NULL && k==0) return head;

    Node* tail = head;
    int len = 1;
    while(tail->next != NULL){
        tail = tail->next;
        len += 1;
    }

    if(k % len == 0) return head; //this is for large value
    k = k % len;

    tail->next = head;  //attach the tail to the head
    Node* newLastNode = findNthNode(head, len-k);

    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}
int main(){
    vector<int> arr ={1,5,2,3,6};
    Node* head = constructLL(arr);
    head = RotateLL(head, 2);
    print(head);
}



