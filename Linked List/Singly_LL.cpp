#include <bits/stdc++.h> 
using namespace std;

class Node {
    
    public:
    int data;
    Node* next;
    

//constructor

    Node(int data){
          this-> data=data;
          this-> next=NULL;
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

//Singly Linked List
void InserAtHead(Node* &head,Node* &tail,int d){
 if(head==NULL){
    Node* temp=new Node(d);
    head=temp;
    tail=temp;
 }
  //new node create
  Node* temp= new Node(d);
  temp->next=head;
  head=temp;
    
}


void InserAtTail(Node* &head,Node* &tail,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }else{
    Node*temp=new Node(d);
    tail->next=temp;
    tail=temp;
    }

}

void InsertAtPosition(Node* &tail,Node* &head,int position,int d){
    // insert at start
    if(position==1){
        InserAtHead(head,tail,d);
        return;
    }

    // insert at middle
    Node*temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    // insertig at last position
    if(temp->next==NULL){
        InserAtTail(head,tail,d);
        return;
    }
    //creating the node which we want to insert in between
    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}
void DeleteNode(Node* &head,Node* &tail,int position){

    if(position==1){
        Node*temp = head;
        head=head->next;
        //memory free start node
        temp->next=NULL;
        delete temp;
    }else{
        //deleting any middle or ending node
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
 
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    //    if(prev->next=NULL){
    //     tail->data=prev->data;
    //     return;
    //     }
     
    }
}

bool isCircularLinkedList(Node* &head){
    if(head==NULL){
        return NULL;
    }
    Node* temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }

    if(temp==head){
        return true;
    }
        return false;
    
}

bool detectLoop(Node* &head){
    if(head==NULL|| head->next==NULL){
        return false;
    }
    Node* temp=head;
     map<Node*, bool> visited;

     while(temp!=NULL){
        //cycle detected
        if(visited[temp]==true){
            cout<<"Present on Element "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
     }
     
     return false;
}

Node* FloydDetectTest(Node* &head){
    if(head==NULL){
        return NULL;
    }

    Node* fast=head;
    Node* slow=head;
    
    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!= NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            cout<< "Present at "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* &head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection=FloydDetectTest(head);
    if(intersection==NULL){
        return NULL;
    }
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

Node* RemoveLoop(Node* &head){
      if(head==NULL){
        return NULL;
    }
    Node* startOfLoop=getStartingNode(head);
    if(startOfLoop==NULL){
        return head;
    }
    Node* temp=startOfLoop;
    
    while(temp->next!=startOfLoop){
            temp=temp->next;
    }

    temp->next=NULL;
    return head;

}

void print (Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
  
}


int main(){
//created a new node
//    Node* node1= new Node(10);          //
//    cout<<node1->data<<endl;         // Constructor
//    cout<<node1->next<<endl;         //


//created a new node
//    Node* node1= new Node(10);          //
//Node pointed to head                    //
//    Node* head=node1;                   //
//    print(head);                        //
//    InserAtHead(head,tail,12);               //
//    print(head);                        //   Insertion at start 15,12,10
//    InserAtHead(head,tail,15);               //
//    print(head);                        //

   
   
// //created a new node
//    Node* node1= new Node(10);           // 
//    //Node pointed to head               //
//    Node* head=node1;                    //
//    Node* tail=node1;                    //
//    print(head);                         //
//    InserAtTail(head,tail,12);                 //   Insertion at end 10,12,15
//    print(head);                          //
//    InserAtTail(head,tail,15);                 //
//    print(head);                          //





// //created a new node
//    Node* node1= new Node(10);           // 
//    //Node pointed to head               //
//    Node* head=node1;                    //
//    Node* tail=node1;                    //
//    print(head);                         //
//    InserAtTail(head,tail,12);                 //   Insertion at middle(anywhere) 10,12,22,15
//    print(head);                          //
//    InserAtTail(head,tail,15);                 //
//    print(head);                          //
//    InsertAtPosition(tail,head,4,22);
//    print(head);
//    cout<<"Head "<<head->data<<endl;
//    cout<<"Tail "<<tail->data<<endl;
//    DeleteNode(head,tail,4);                    // Delete the data 
//    print(head);
//    cout<<"Head "<<head->data<<endl;
//    cout<<"Tail "<<tail->data<<endl;



 Node* node1= new Node(10);           // 
   //Node pointed to head               //
   Node* head=node1;                    //
   Node* tail=node1;  
    InserAtTail(head,tail,12);                 //   Insertion at middle(anywhere) 10,12,22,15
   print(head);                          //
   InserAtTail(head,tail,15);                 //
   print(head);                          //
   InsertAtPosition(tail,head,4,22);
   print(head);
    cout<<"Head "<<head->data<<endl;
   cout<<"Tail "<<tail->data<<endl;
   tail->next=head->next;
       cout<<"Head "<<head->data<<endl;
   cout<<"Tail "<<tail->data<<endl;
//    if(detectLoop(head)){
//     cout<<"Cycle is present "<<endl;
//    }else{
//     cout<<"No Cycle "<<endl;
//    }
if(FloydDetectTest(head)!=NULL){
    cout<<"Cycle is present "<<endl;
   }else{
    cout<<"No Cycle "<<endl;
   }
   Node* loop= getStartingNode(head);
   cout<<"Loop starts at "<<loop->data << endl;
   RemoveLoop(head);
   print(head);
   
}