#include <bits/stdc++.h> 
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
   
   //constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    //destructor
     ~Node(){
        int value= this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data "<< value<<endl;
    }


};

void InsertAtHead(Node* &head,Node* &tail,int d){
   
   if(head==NULL){
    Node* temp=new Node(d);
    head=temp;
    tail=temp;
   }else{
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
   }

}
void InsertAtTail (Node* &head,Node* &tail,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }else{
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}

void InsertAtPosition(Node* &head,Node* &tail,int position,int d){
    
    if(position==1){
      InsertAtHead(head,tail,d);
      return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        InsertAtTail(head,tail,d);
        return;
    }
  Node* NodeToInsert=new Node(d);
  NodeToInsert->next=temp->next;
  temp->next->prev=NodeToInsert;
  temp->next=NodeToInsert;
  NodeToInsert->prev=temp;
}

// void DeleteNode(Node* &head,int position){
// if(position==1){
//     Node* temp=head;
//     temp->next->prev=NULL;
//     head=temp->next;
//     temp->next=NULL;
//     delete temp;
// }else{
//     //deleting any middle or last node
//     Node* curr=head;
//     Node* prev=NULL;

//     int cnt=1;
//     while(cnt<position-1){
//         prev=curr;
//         curr=curr->next;
//         cnt++;
//     }
   
//    curr->prev=NULL;
//    prev->next=curr->next;
//  if(prev->next != NULL)
// curr->next->prev = prev;     
// curr->next=NULL;
//     delete curr;
// }
// }


void DeleteNode(Node* &head,Node* &tail,int position)
{   //checking for head deletion
    if(position==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;    
    }
    else    // tail and middle case
    {
        Node* curr=head;
        Node* prev = NULL;

        int cnt=1;

        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        //for tail deletion (to adjust the tail)
        if(curr->next==NULL)
        {
            tail=prev;
            prev->next=curr->next;  // null
            curr->prev=NULL;
            delete curr;
            return ;
        }
        // below case only execute when positoin is not head or tail
        // here only 1 step is neglected in the tail block
        curr->next->prev=curr->prev;
        prev->next=curr->next;
        curr->next=NULL;
        curr->prev=NULL;

        delete curr;
    }

}


// traversing a linked list
void print(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//gives length of linked list
void getLength(Node* &head){
    Node* temp= head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    cout<<len<<endl;
}


int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    getLength(head);
    InsertAtHead(head,tail,11);
    print(head);
    InsertAtHead(head,tail,13);
    print(head);
    InsertAtTail(head,tail,25);
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    InsertAtPosition(head,tail,2,100);
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    DeleteNode(head,tail,5);
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;

}
