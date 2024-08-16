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

    void inorder(BinaryTreeNode* root,vector<int> &ans){
    if(root==NULL){
        return ;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

BinaryTreeNode*flatten(BinaryTreeNode* root)
{
    //vector to store inorder sorted values
    vector<int>ans;
    inorder(root,ans);
// creating 1st element
    BinaryTreeNode* newRoot=new BinaryTreeNode(ans[0]);
    BinaryTreeNode* curr=newRoot;

    int n=ans.size();
//process for element from 1 to last
    for(int i=1;i<n;i++){
        BinaryTreeNode* temp=new BinaryTreeNode(ans[i]);
        temp->left=NULL;
        curr->right=temp;
        curr=temp;
    }
     
     //last element
     curr->left=NULL;
     curr->right=NULL;
     return newRoot;
}