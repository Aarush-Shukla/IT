#include <bits/stdc++.h> 
using namespace std;

// Structure of node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// T.C- O(N)+O(N)+O(N)

int TotalCount(struct Node* root){
      if(root==NULL){
          return 0;
      }
      int ans=1+TotalCount(root->left)+TotalCount(root->right);
      return ans;
      
  }
  
  bool isCBT(struct Node* root,int index,int nodeCount){
      if(root==NULL){
          return true;
      }
      if(index>=nodeCount){
          return false;
      }else{
          bool left=isCBT(root->left,2*index+1,nodeCount);
          bool right=isCBT(root->right,2*index+2,nodeCount);
          return (left && right);
      }
  }
  
  bool MaxHeap(struct Node* root){
      //leaf node
      if(root->left==NULL && root->right==NULL){
          return true;
      }
      //only left child exists
      if(root->right==NULL){
          return (root->data > root->left->data);
      }
      //both child exists
      else{
          bool left=MaxHeap(root->left);
          bool right=MaxHeap(root->right);
          
          return (left && right && (root->data > root->left->data && root->data > root->right->data));
      }
  }
  
    bool isHeap(struct Node* tree) {
        int index=0;
        int nodeCount= TotalCount(tree);
        //check for both complete binary tree and heap properties
       if(isCBT(tree,index,nodeCount) && MaxHeap(tree)){
           return true;
       } else{
           return false;
       }
    }