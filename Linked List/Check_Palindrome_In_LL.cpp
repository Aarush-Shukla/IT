#include <bits/stdc++.h> 
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// (Approach 1)-T.c(O(n)), S.c(O(n));
    // bool checkPalindrome(vector<int> arr){
    //     int n=arr.size();
    //     int s=0;
    //     int e=n-1;
    //     while(s<=e){
    //         if(arr[s]!=arr[e]){
    //             return 0;
    //         }
    //         s++;
    //         e--;
    //         }
    //         return 1;
    // }
    
    // bool isPalindrome(Node *head)
    // {
    //     vector<int> arr;
    //     Node* temp=head;
    //     while(temp!=NULL){
    //         arr.push_back(temp->data);
    //         temp=temp->next;
    //     }
    //     return checkPalindrome(arr);
    // }





// (Approach 2)-T.c(O(n)), S.c(O(1));

 Node* reverse(Node* &head){
       Node* curr=head;
       Node* prev=NULL;
       Node* forward=NULL;
       
       while(curr!=NULL){
           forward=curr->next;
           curr->next=prev;
           prev=curr;
           curr=forward;
       }
       return prev;
   }
   
   Node* findMiddle(Node* &head){
       Node* fast=head->next;
       Node* slow=head;
       
       while(fast!=NULL&& fast->next!=NULL){
           fast=fast->next->next;
           slow=slow->next;
       }
       return slow;
   }
    
    bool isPalindrome(Node *head)
    {
    //     vector<int> arr;
    //     Node* temp=head;
    //     while(temp!=NULL){
    //         arr.push_back(temp->data);
    //         temp=temp->next;
    //     }
    //     return checkPalindrome(arr);
    
    if(head==NULL|| head->next==NULL){
        return true;
    }
    
     //step1- find Midddle
    Node* middle=findMiddle(head);
    //step2- reverse the second part
    Node* temp=middle->next;
    middle->next=reverse(temp);
    //step3- compare the two halves;
    Node* head1=head;
    Node* head2= middle->next;
    
    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
  
    //step4- repeat step 2 once again to reatin the original Linked List
    temp=middle->next;
    middle->next=reverse(temp);
    
    
    return true;
    
    }