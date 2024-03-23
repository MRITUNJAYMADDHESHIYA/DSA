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


//time=O(n1* map)+O(n2* map),space=O(N1 OR N2)
Node* IntersectionLL1(Node* head1, Node* head2){
    map<Node*, int> mpp;
    Node* temp = head1;
    while(temp != NULL){
        mpp[temp] = 1;  //map store the node not value
        temp = temp->next;
    }

    Node* temp = head2;
    while(temp != NULL){
        if(mpp.find(temp) == mpp.end()){
            return temp;
            temp = temp->next;
        }
    }
    return NULL;
}


//space=O(1)
Node* collisionPoint(Node* head1, Node* head2, int d){
    while(d){  //time=O(n1-n2)
        d--;
        head2 = head2->next;
    }
    while(head1 != head2){   //time=O(n1)
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}

Node* IntersectionLL2(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    int n1 = 0, n2 = 0;
    while(t1 != NULL){   //time=O(n1)
        n1++;
        t1 = t1->next;
    }
    while(t2 != NULL){   //time=O(n2)
        n2++;
        t2 = t2->next;
    }

    if(n1 < n2){
        return collisionPoint(head1, head2, n2-n1);
    }
    else{
        return collisionPoint(head2, head1, n1-n2);
    }
}


//Important:- Take two dummy nodes for each list. Point each to the head of the lists.
// Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.
//time=O(N1+N2)
//space=O(1)
Node* IntersectionLL3(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    Node* t1 = head1;
    Node* t2 = head2;

    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;

        if(t1 == t2) return t1;

        if(t1 == NULL) t1 = head2;
        if(t2 == NULL) t2 = head1;
    }
    return t1;
}