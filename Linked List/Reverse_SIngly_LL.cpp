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
            this->data = data;
            this->next = NULL;
        }
    };

    LinkedListNode<int>* solve(LinkedListNode<int>* &head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    LinkedListNode<int>* ChotaHead= solve(head->next);

    head->next->next=head;
    head->next=NULL;
    return ChotaHead;
}


// void reverse(LinkedListNode<int>* &head,LinkedListNode<int>* &curr,LinkedListNode<int>* &prev){
//     //base case
//     if(curr==NULL){
//     head=prev;
//     return;
//     }
    
    
//     LinkedListNode<int>* forward= curr->next;
//     reverse(head,forward,curr);
//     curr->next=prev;
// }

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{

return solve(head);


//  LinkedListNode<int>* prev=NULL;
//  LinkedListNode<int>* curr=head;
//  reverse(head,curr,prev);
//  return head;   




//     //Empty list or List with 1 Node
//     if(head==NULL || head->next==NULL){
//         return head;
//     }
//   LinkedListNode<int>* prev=NULL;
//   LinkedListNode<int>* curr=head;
//   LinkedListNode<int>* forward=NULL;
  
//   while(curr!=NULL){
//       forward=curr->next;
//       curr->next=prev;
//       prev=curr;
//       curr=forward;
//   }

//   return prev;
}