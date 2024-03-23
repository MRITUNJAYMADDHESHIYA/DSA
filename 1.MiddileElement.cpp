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

//time=O(N+N/2),space=o(1)
Node* middileElement1(Node* head){
    //It's find the size of array
    int n = 0;
    Node* temp = head;
    while(temp) {
        n++;
        temp = temp->next;
    }

    temp = head;
    for(int i=0; i< n/2; i++){
        temp = temp->next;
    }
    return temp;
}

//tortoise and hare
//time=o(N),space=O(1)
Node* middileElement2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> arr = {4,5,2,6,3,7};
    Node* head = constructLL(arr);
    head = middileElement1(head);
    print(head);
    return 0;
}
