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

//time=o(2N),space=O(N)
bool PalindromeLL1(Node* head){
    stack<int> st;
    Node* temp = head;

    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        if(temp->data != st.top()){
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}

Node* reverseLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}


//time=O(2*n),space=O(1)
bool PalindromeLL2(Node* head){
    if(head == NULL || head->next == NULL){return true;}

    Node* slow = head;
    Node* fast = head;

    //odd and even node
    //time=O(n/2)
    while(fast->next != NULL && fast->next->next != NULL){
         slow = slow->next;  
         fast = fast->next->next;
    } 

    Node* newHead = reverseLL(slow->next); //revese the second half //time=O(n/2)

    Node* first = head; //first half
    Node* second = newHead; //second half

    while(second != NULL){//time=O(n/2)
        if(first->data != second->data){
            reverseLL(newHead); //original form

            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLL(newHead);//original form//time=O(n/2)
    return true;
}

int main(){
    vector<int> arr = {7,2,3,2,1};
    Node* head = constructLL(arr);
    if(PalindromeLL2(head)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}