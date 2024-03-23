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

Node* reverseLL(Node* head){
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

Node* findKthNode(Node* temp, int k){
     k-=1;
     while(temp != NULL && k>0){
        k--;
        temp = temp->next;
     }
     return temp;
}
  
//time=O(N)+O(n),sapce=o(1)
Node* reverseGroup(Node* head, int k){
    Node* temp = head;
    Node* prevNode = NULL;
    
    while(temp != NULL){
        Node* Kthnode = findKthNode(temp, k);

        //if size is less than k
        if(Kthnode == NULL){
            if(prevNode) return prevNode->next = temp;
            break;
        }

        //before the sepreation store the next node
        Node* nextNode = Kthnode->next;   //1st element of 2nd group
        Kthnode->next =NULL;              //sepreate the 1st group from 2nd
        reverseLL(temp);

        //Identify the first group or after the first group
        if(temp == head){
            head = Kthnode;  //update the head
        }
        else{  //after the first group
            prevNode->next =  Kthnode;  //last element of 1st group must be attach with kth element of 2nd group
        }

        prevNode = temp;  //last element of 1st group
        temp = nextNode;        //1st element of 2nd group
    }
    return head;
}



// Node* reverseKGroup(Node* head, int k) {
//     if(!head or k==1) return head;

//     Node* temp = new Node;
//     temp->next=head;

//     Node* curr=temp, *nex=temp, *prev=temp;
//     int count=0;

//     while(curr->next!=NULL){
//         curr=curr->next;
//         count++;
//     }

//     while(count>=k){
//         curr=prev->next;
//         nex=curr->next;
//         for(int i=1;i<k;i++){
//             curr->next=nex->next;
//             nex->next=prev->next;
//             prev->next=nex;
//             nex=curr->next;
//         }
//         prev=curr;
//         count=count-k;
//     }
//     return temp->next;
// }

int main(){
    vector<int> arr ={5, 4, 3, 7, 9, 3, 2};
    Node* head = constructLL(arr);
    head = reverseGroup(head, 3);
    print(head);
}

