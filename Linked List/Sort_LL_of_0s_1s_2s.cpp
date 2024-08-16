#include <bits/stdc++.h> 
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


//(Approach 1) if we want to change the data in same Linked List

Node* sortList(Node *head){
   
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;

    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zeroCount++;
        }
        else if(temp->data==1){
            oneCount++;
        }else if(temp->data==2){
            twoCount++;
    }
    temp=temp->next;
    }

    temp=head;
    while(temp!=NULL){
        if(zeroCount!=0){
            temp->data=0;
            zeroCount--;
        }else if(oneCount!=0){
            temp->data=1;
            oneCount--;
        }else if(twoCount!=0){
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
    return head;
}


//(Approach 2) if we do not want to change the data in LL

void InsertAtTail(Node* &tail,Node* curr){
    tail->next=curr;
    tail=curr;
    }
    Node* sortList(Node *head){
         Node* zeroHead=new Node(-1);
    Node* zeroTail=zeroHead;
    Node* oneHead=new Node(-1);
    Node* oneTail=oneHead;
    Node* twoHead=new Node(-1);
    Node* twoTail=twoHead;

    Node* curr=head;

//create a seperate list of 0s,1s,2s
    while(curr!=NULL){
        int value= curr->data;

        if(value==0){
            InsertAtTail(zeroTail,curr);
        }else if(value==1){
            InsertAtTail(oneTail,curr);
        }else if(value==2){
            InsertAtTail(twoTail,curr);
        }
        curr=curr->next;
    }

    //Merge 3 sublist
    
    //1s list not empty
    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
    }else{
        //1s list Empty
        zeroTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoTail->next=NULL;
   //set up head
    head=zeroHead->next;
   //delete extra dummy pointers
   delete(zeroHead);
   delete(oneHead);
   delete(twoHead);

   return head;
}



