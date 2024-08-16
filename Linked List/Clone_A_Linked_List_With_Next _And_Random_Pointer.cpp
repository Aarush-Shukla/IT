#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* arb;
    Node(int x) {
        data = x;
        next = NULL;
        arb=NULL;
    }
};

// //(Approach 1) T.C-(O(N)), S.C-(O(N))
//  void insertAtTail(Node* &head,Node* &tail,int d){
//         Node* temp=new Node(d);
//         if(head==NULL){
//             head=temp;
//             tail=temp;
//             return;
//         }else{
//              tail->next=temp;
//              tail=temp;
//         }
//     }
    
    
//     Node *copyList(Node *head)
//     {
        
//         Node* cloneHead=NULL;
//         Node* cloneTail=NULL;
        
//         Node* temp=head;
        
//         //step 1- clone the Linked List
//         while(temp!=NULL){
//             insertAtTail(cloneHead,cloneTail,temp->data);
//             temp=temp->next;
//         }
        
//         //step 2- create a map
//         unordered_map<Node*,Node*> oldtonew;
//         Node* OriginalNode=head;
//         Node* NewNode=cloneHead;
        
//         //step 3- mapping original and new node
//         while(OriginalNode!= NULL && NewNode!=NULL){
//             oldtonew[OriginalNode]=NewNode;
//             OriginalNode=OriginalNode->next;
//             NewNode=NewNode->next;
//             }
//             OriginalNode=head;
//             NewNode=cloneHead;
            
            
//             //step 4- pointing th randomn pointer at its right place 
//             while(OriginalNode!=NULL){
//                 NewNode->arb=oldtonew[OriginalNode->arb];
//                 OriginalNode=OriginalNode->next;
//                 NewNode=NewNode->next;
//             }
            
//         return cloneHead;
//         }





//(Approach 2) T.C-(O(N)), S.C-(O(1))
  private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    void print(Node* head) {
        while(head != NULL) {
            cout << head -> data << " ";
            head = head -> next;
        }cout << endl;
    }

    void printRandom(Node* head) {
        while(head != NULL) {
            cout << " head data: " << head->data <<" ";
            if(head ->arb != NULL) {
                cout << " head random data" << head -> arb ->data;
            }
            else
            {
                cout << " head random data: NULL";
            }
            head = head -> next;
            cout << endl;
        }
    }

    public:
    Node *copyList(Node *head)
    {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // step 2: insert nodes of Clone List in between originalList
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        // step 3: Random pointer copy
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) { 
            
            if(originalNode -> arb != NULL) {
                cloneNode -> arb = originalNode -> arb -> next;
            }
            else
            {
                cloneNode -> arb  = NULL;
            }
            
            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
        }
        
        //step 4: revert step 2 changes
        Node* original = head;
        Node* copy = cloneHead;
        
         while (original && copy)
            {
                original->next =
                 original->next? original->next->next : original->next;
         
                copy->next = copy->next?copy->next->next:copy->next;
                original = original->next;
                copy = copy->next;
            }

        // step 5 answer return
        return cloneHead;
    }