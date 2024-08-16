#include <bits/stdc++.h> 
using namespace std;

template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
        }
    };

LinkedListNode<int>* reverseDoublyLL(LinkedListNode<int>* &head){
if(head==NULL || head->next==NULL){
return head;
}

LinkedListNode<int>* temp=head;
LinkedListNode<int>* store=NULL;
while(temp!=NULL){
//Swapping the addresses 
store=temp->prev;
temp->prev=temp->next;
temp->next=store;
temp=temp->prev;}
return store->prev;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{

return reverseDoublyLL(head);
}