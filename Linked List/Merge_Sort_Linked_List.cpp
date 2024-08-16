#include <bits/stdc++.h> 
using namespace std;
  
  class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };

node* findMiddle(node* &head){
   node* slow = head;
    node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;

}


node* solve(node* &first, node* &second){

// if only one element is present in first list
if(first->next==NULL){
    first->next=second;
    return first;
}

    node* curr1=first;
    node* for1=curr1->next;
    node* curr2=second;
    node* for2=curr2->next;

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

node* merge(node* &first,node* &second){
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

node* mergeSort(node *head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    //break linked list into two halves,after finding mid
    node* mid=findMiddle(head);
    node* left=head;
    node* right=mid->next;
    mid->next=NULL;

    //use recursion to sort them
    left=mergeSort(left);
    right=mergeSort(right);

    //merge the two sorted arrays
    node* ans= merge(left,right);
    return ans; 
}