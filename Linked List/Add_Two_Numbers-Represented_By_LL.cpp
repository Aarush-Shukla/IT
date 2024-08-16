#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

  Node* reverse(Node* head){
        Node* curr=head;
        Node* prev= NULL;
        Node* forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    
    
    void insertAtTail(struct Node* &head, struct Node* &tail,int digit){
        
        Node* temp=new Node(digit);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }else{
            tail->next=temp;
            tail=temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        
        int carry=0;
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        
        while(first!=NULL && second!=NULL){
            int sum=carry + first->data + second->data;
            int digit= sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            first=first->next;
            second=second->next;
        }
        while(first!=NULL){
            int sum=carry + first->data;
            int digit= sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            first=first->next;
        }
         while(second!=NULL){
            int sum=carry + second->data;
            int digit= sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            second=second->next;
        }
         while(carry!=0){
            int sum=carry;
            int digit= sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
        }
        return ansHead;
    }
    
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
      //step1-reverse both the LL
      first=reverse(first);
      second=reverse(second);
      
      //step2 add both the ans
      Node* ans=add(first,second);
      
      //step3 reverse the LL
      ans=reverse(ans);
      
      return ans;
      
    }