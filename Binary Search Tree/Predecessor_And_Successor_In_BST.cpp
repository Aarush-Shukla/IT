#include <bits/stdc++.h> 
using namespace std;

class BinaryTreeNode 
    {
    public : 
        int data;
       BinaryTreeNode* left;
       BinaryTreeNode* right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

    pair<int,int> predecessorSuccessor(BinaryTreeNode* root, int key)
{
    BinaryTreeNode* temp=root;
    int pred = -1;
    int succ = -1;

// checking potenital succ and pred

    while(temp->data != key){
        if(temp->data > key){
            
            succ=temp->data;
            temp=temp->left;

        }else{
              
            pred=temp->data;
            temp=temp->right;

        }

    }

//defining pred and succ in left and right of temp
//pred
BinaryTreeNode* leftTree=temp->left;
while(leftTree!=NULL){
    pred=leftTree->data;
    leftTree=leftTree->right;
}
//succ
BinaryTreeNode* rightTree=temp->right;
while(rightTree!=NULL){
    succ=rightTree->data;
    rightTree=rightTree->left;
}

pair<int,int> ans=make_pair(pred,succ);
return ans;

}