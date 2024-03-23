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

// Node* jumpMethod(Node* head){
//     if(head == NULL && head->next == NULL){
//         return head;
//     }
//     int arrr[];    
//     //for odd index
//     //time=O(N/2)
//     Node* temp = head;
//     while(temp != NULL && temp->next != NULL){
//         arr.add(temp->data);
//         temp = temp->next->next;
//     }
//     if(temp) arr.add(temp->data);
//     //for even index
//     //time=O(N/2)
//     Node* temp = head->next;
//     while(temp != NULL && temp->next != NULL){
//         arr.add(temp->data);
//         temp = temp->next->next;
//     }
//     if(temp) arr.add(temp->data);
//     //put in linkedlist 
//     //time=O(N)
//     //space=O(N) because of array
//     int i= 0;
//     Node* temp = head;
//     while(temp != NULL){
//         temp->data = arr[i];
//         i++;
//         temp = temp->next;
//     }
//     return head;
// }
Node* oddEvenList(Node* head){
    if(head == NULL && head->next == NULL) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    //time=O(N)
    //SPACE=o(1)
    while(even != NULL && even->next != NULL){

        odd->next = odd->next->next;
        even->next = even->next->next;
        
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main(){
    vector<int> arr = {12,6,3,5,4,2};
    Node* head = constructDLL(arr);
    head = oddEvenList(head);
    print(head);
    return 0;
    }

