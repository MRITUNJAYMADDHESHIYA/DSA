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


//time=O(N *2*map depend),Space=O(n)
bool cycleLL1(Node* head){
    Node* temp =head;
    std::unordered_map<Node*, int> nodeMap;

    while(temp != NULL){

        if(nodeMap.find(temp) == nodeMap.end()){  //find the node in the map
            return true; //return temp;
        }

        nodeMap[temp] = 1;  //inserting in the map

        temp = temp->next;
    }
    return false; //return null;
}


//Important
//time=O(N)
//space=O(1)
bool cycleLL2(Node* head){
    Node* slow = head;
    Node* fast = slow;
    while(fast != NULL && fast->next != NULL){ //odd and even
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}



//find the starting point of the node
//time=O(N),space=O(1)
Node* firstnode(Node* head){
    if(head == NULL || head->next == NULL){return NULL;}

    Node* slow = head;
    Node* fast = head;
    Node* entry = head;

    while(fast->next != NULL && fast->next->next != NULL){ //odd and even
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            while(slow != entry){
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;

}



int main() {
    // Create a sample linked list
    // with a loop for testing
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 

    // Check if there is a loop 
    // n the linked list
    if (cycleLL2(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}