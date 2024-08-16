#include <bits/stdc++.h> 
using namespace std;

struct Node{
int key;
Node* left, *right;

Node* newNode(int key){
    Node* node=new Node;
    node->key=key;
    node->left=node->right=NULL;
    return (node);
    }
};

 void flatten(Node *root)
    {
        Node* curr=root;
        while(curr!=NULL){
            if(curr->left){
                Node* pred=curr->left;
                while(pred->right){
                pred=pred->right;
                }
                
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }