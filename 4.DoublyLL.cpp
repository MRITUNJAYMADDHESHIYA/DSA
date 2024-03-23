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

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    
    Node* prev = head;
    head = head->next;

    head->back = nullptr;    //new head back have to nullptr
    prev->next = nullptr;    

    return head;
}
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* tail = head;
    while(tail->next != NULL){   //This loop for going at last element
        tail = tail->next;
    }

    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}
//Important
Node* removeKthElement(Node* head, int k){
    if(head == NULL) return NULL;

    // temp is stand with kth element
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL) return NULL;   //for single element
    else if(prev == NULL) return deleteHead(head);
    else if(front == NULL) return deleteTail(head);

    prev->next = front;  //first join then breack the DLL
    front->back = prev;

    temp->back = nullptr;
    temp->next = nullptr;
    delete temp;

    return head;
}
//Delete the Node, but not for head
void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){    //for the last element 
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

    prev->next = front;
    front->back = prev;
    
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
}

Node* insertBeforeHead(Node* head, int value){
    Node* newhead = new Node(value, head, nullptr);
    head->back = newhead;
    return newhead;
}
Node* insertBeforeTail(Node* head, int value){
    if(head->next == NULL){   //for one element
        return insertBeforeHead(head, value);
    }

    Node* tail = head;
    while(tail->next != NULL){   //go at last element
        tail = tail->next;
    }

    Node* prev = tail->back;    
    Node* newNode = new Node(value,tail, prev);   //putting new Node inside the tail and prev new Node(value,after, before);

    prev->next = newNode;    //prev and tail join with new Node
    tail->back = newNode;

    return head;

}
Node* insertAfterTail(Node *head, int k) {
    if(head == NULL){
        return new Node(k);
    }

    Node* tail =head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* newNode = new Node(k, nullptr, tail); //for new node adding at the end
    tail->next = newNode;
    return head;
}
Node* insertBeforeKthElement(Node* head, int value, int k){
    if(k == 1){
        return insertBeforeHead(head, value);
    }
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp->next;
    }
    Node* prev =temp->back;
    Node* newNode = new Node(value, temp, prev); //putting new NOde inside the temp and prev

    prev->next = newNode;
    temp->back = newNode;

    return head;
}
//Delete the Node, but not for head(because head will be new head when i want to change the head)
void insertBeforeNode(Node* node, int value){
    Node* prev = node->back;
    Node* newNode = new Node(value, node, prev);

    prev->next = newNode;
    node->back = newNode;
}

int main(){
    vector<int> arr = {4,10,3,5};
    Node* head = constructDLL(arr);
    //head = deleteHead(head);
    //head = deleteTail(head);
    //head = removeKthElement(head, 5);
    //deleteNode(head->next);
    head = insertBeforeHead(head, 20);
    //head = insertBeforeTail(head, 15265);
    //head = insertAfterTail(head,5351);
    //head = insertBeforeKthElement(head,45000, 3);
    //insertBeforeNode(head->next->next, 50000);
    print(head);    
    return 0;
}