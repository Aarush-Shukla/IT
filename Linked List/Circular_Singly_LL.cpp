#include <bits/stdc++.h> 
using namespace std;

class Node{
    public:
    int data;
    Node* next;

//constructor
    Node(int d){
        this->data=d;
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

void InsertAtNode(Node* &tail,int element,int d){
  
  //If the List is empty
   if(tail==NULL){
    Node* temp=new Node(d);
    tail=temp;
    temp->next=temp;
    }
//if the list is non empty
else{
    Node* curr=tail;

    while(curr->data!=element){
        curr=curr->next;
    }
    
    Node* temp=new Node(d);
    temp->next=curr->next;
    curr->next=temp;
}
}

void DeleteNode(Node* &tail,int value){
    //empty list
    //0 Node LL
    if(tail==NULL){
        cout<<"List is empty "<<endl;
        return;
    }else{
        //the list is non empty
        //assuming the value is present in the list
        Node* prev=tail;
        Node* curr=prev->next;

        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;
         
        // 1 Node LL 
        if(curr==prev){
            tail=NULL;
        }

        // >=2 Node LL
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;

    }
}

void print(Node* &tail){
    Node* temp=tail;
    
    //Empty List
     if(tail==NULL){
        cout<<"List is empty "<<endl;
        return;
    }

    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<endl;
}
int main(){
    Node* tail=NULL;
    
    InsertAtNode(tail,5,3);
    print(tail);
    // InsertAtNode(tail,3,5);
    // print(tail);
    // InsertAtNode(tail,5,7);
    // print(tail);
    // InsertAtNode(tail,7,9);
    // print(tail);
    // InsertAtNode(tail,3,4);
    // print(tail);
    // InsertAtNode(tail,5,6);
    // print(tail);
    // InsertAtNode(tail,9,10);
    // print(tail);
    // DeleteNode(tail,3);
    // print(tail);
    // DeleteNode(tail,3);
    // print(tail);
    // DeleteNode(tail,3);
    // print(tail);
    DeleteNode(tail,3);
    print(tail);

}
