#include <bits/stdc++.h>
using namespace std;

 class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

    
// Node* solve(Node* &head){
//   Node* curr = head;
//     Node* prev = NULL;
//     unordered_map<int, bool> visited;
    
//     while(curr != NULL){
//         if(!visited[curr->data]){
//             visited[curr->data] = true;
//             prev = curr;
//             curr = curr -> next;
//         }
//         else{
//             prev -> next = curr -> next;
//             delete curr;
//         }
//         curr = prev -> next;
//     }
//     return head;

// }


Node *removeDuplicates(Node *head)
{
    // return solve(head);


//o(n^2) method
//  Node* curr = head;
//     while(curr!=NULL && curr->next != NULL){
//         Node* temp = curr;
//         while(temp->next!=NULL){
//             if(temp->next->data == curr->data){
//                 Node* next = temp->next;
//                 temp -> next = temp->next->next;
//                 delete(next);
//             }
//             else{
//                 temp = temp->next;
//             }
//         }
//         curr = curr->next;
//     }
//     return head;

// 
}