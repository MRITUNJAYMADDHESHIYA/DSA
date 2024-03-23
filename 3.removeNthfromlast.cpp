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

//time=O(2*length), space= O(1)
Node* removeNthFromLast1(Node* head, int N){
    int count = 0;
    Node* temp = head;

    //find the length of LL
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    //for N == length of LL
    if(count == N){
        Node* newhead = head->next;
        free(head);
        return newhead;
    }

    int res = count - N;
    temp = head;
    while(temp != NULL){
        res--;
        if(res == 0) break; //this is temp, when res == 0
        temp = temp->next;  //I want to go temp->next
    }
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        free(delNode);
        return head;
    }

//time=O(length), space =O(1)
Node* removeNthFromLast2(Node*head ,int N){
    Node* fast = head;
    Node* slow = head;
    for(int i=0; i<N; i++){fast = fast->next;} //after the loop fast at N from starting point

    if(fast == NULL){return head->next;}//for N == length of LL
    //after this loop we are standing at prev of the delNode
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);
    return head;
}

int main(){
    vector<int> arr = {4,1,2,3,6,5};
    Node* head = constructLL(arr);
    head = removeNthFromLast2(head, 2);
    print(head);
}