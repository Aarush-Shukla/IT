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

    
class compare{
    public:
    bool operator()(Node<int>* a, Node<int>* b){
        return a->data > b->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*,vector<Node<int>*>,compare> minHeap;

    int k=listArray.size();

    if(k==0){
        return NULL;
    }

    for(int i=0;i<k;i++){
      if (listArray[i] != NULL) {
        minHeap.push(listArray[i]);
      }
    }
    Node<int>* head=NULL;
    Node<int>* tail=NULL;

    while(minHeap.size()>0){
        Node<int>* temp= minHeap.top();
        minHeap.pop();

         
         if(head==NULL){
             head=temp;
             tail=temp;
             
        }else{
             tail->next=temp;
             tail=temp;
            }

    
        if(temp->next != NULL){
                    minHeap.push(temp->next);
                }

    }
    return head;

}