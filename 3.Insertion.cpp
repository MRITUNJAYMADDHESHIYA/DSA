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

//Inserting head
Node* insertingHead(Node* head, int value){
    return new Node(value, head);
}

//Inserting Tail
Node* insertingTail(Node* head, int value){
    if(head == NULL) return new Node(value);   

    Node* temp = head;
    while(temp->next != NULL){    //Last element
        temp = temp->next;
    }

    Node* newNode= new Node(value);  // put the value
    temp->next = newNode;            //inserting in linkedlist
    return head;
}

//For Kth place
Node* insertingPosition(Node* head, int value, int k){

    if(head == NULL){            // for null element present in linkedlist
        if(k==1){return new Node(value);}
        else{return head;}
    }

    if(k == 1){return new Node(value, head);}   // for head position

    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k-1){          
            Node* x =new Node(value, temp->next);   
            temp->next = x;
            break;
        }        
        temp = temp->next;
    }
    return head;
}

//Insrting value before the x element
Node* insertingBeforeElement(Node* head, int value, int element){

    if(head == NULL){            // for null element present in linkedlist
        return NULL;
    }

    if(head->data == value){return new Node(value, head);}   // for head position

    Node* temp = head;
    while(temp->next != NULL){  //not going at last position
        if(temp->next->data == element){          
            Node* x =new Node(value, temp->next);   
            temp->next = x;
            break;
        }        
        temp = temp->next;
    }
    return head;
}


Node* reverseLL1(Node* head){
    Node* temp = head;
    stack<int> st;                   
    //go in the stack             //time=O(2N), space=O(N)
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    //out of the stack
    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

//Very Important for reversae the LL
Node* reverseLL2(Node* head){
    Node* temp = head;
    Node* prev = NULL;               //time=O(N), space=O(1)
    while(temp != NULL){
        Node* front = temp->next;  
        temp->next = prev;        //it's join the prev value
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* reverseLL3(Node* head){
    if(head ==NULL || head->next == NULL){
        return head;                             //time=O(N),space=O(N)
    }
    Node* newHead = reverseLL3(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main(){
    vector<int> arr = {45,2,1,3,6,8};
    Node* head = constructLL(arr);
    //head = insertingHead(head, 5656);
    //head = insertingTail(head, 5656);
    //head = insertingPosition(head, 5000, 1);
    head = insertingBeforeElement(head,46555,6);
    print(head);
}