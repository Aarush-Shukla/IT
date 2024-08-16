#include <bits/stdc++.h> 
using namespace std;

 template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

    Node<int>* solve(Node<int>* first, Node<int>* second){

// if only one element is present in first list
if(first->next==NULL){
    first->next=second;
    return first;
}

    Node<int>* curr1=first;
    Node<int>* for1=curr1->next;
    Node<int>* curr2=second;
    Node<int>* for2=curr2->next;

    while(for1!=NULL && curr2!=NULL){
        if(curr2->data>=curr1->data && curr2->data<=for1->data){
             
             //add node in between the first line
            
            for1=curr1->next;
            curr1->next=curr2;
            for2=curr2->next;
            curr2->next=for1;

            //update pointer
            curr1=curr2;
            curr2=for2;
        }else{// agar upar wali condition mai no aaye toh
            //curr1 aur for1 ko aage badhana padgea
            curr1=for1;
            for1=for1->next;
            if(for1==NULL){
                curr1->next=curr2;
                return first;
            }

        }
    }
   return first;
}


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL)
        return second;
    
    if(second==NULL)
        return first;

        if(first->data<=second->data){
            return solve(first,second);
        }else{
            return solve(second,first);
        }
    }
