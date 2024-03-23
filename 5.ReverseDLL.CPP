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
Node* constructDLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
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

// Using stack method
// timeCompl=O(2N)
// space=O(N)
Node* stackReverse(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        temp->data =st.top();
        st.pop();
        temp = temp->next; 
    }
    return head;
}

//time=O(N)
//space=O(1)
Node* reverseSwap(Node* head){
    if(head == NULL || head->next ==NULL){
        return head;
    }
    
    Node* prev = NULL;
    Node* current = head;
    while(current != NULL){
        prev = current->back;
        current->back = current->next;
        current->next = prev;

        current = current->back;
    }
    return prev->back;
}


int main(){
    vector<int> arr = {12,6,3,5,4,2};
    Node* head = constructDLL(arr);
    head = reverseSwap(head);
    print(head);
    return 0;
    }

/**********For singly LL**********/
// ListNode* reverseList(ListNode* head) {
//     ListNode* temp = head;
//     ListNode* prev = NULL;               //time=O(N), space=O(1)
//     while(temp != NULL){
//         ListNode* front = temp->next;  
//         temp->next = prev;        //it's join the prev value
//         prev = temp;
//         temp = front;
//     }
//     return prev;
// }