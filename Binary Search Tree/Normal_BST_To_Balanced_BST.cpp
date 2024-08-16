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


BinaryTreeNode* inorderToBST(BinaryTreeNode* root,int s, int e, vector<int> &ans){
    if(s>e){
       return NULL;
    }
    int mid=s+(e-s)/2;
    BinaryTreeNode* temp=new BinaryTreeNode(ans[mid]);
    temp->left=inorderToBST(root,s, mid-1,ans);
    temp->right=inorderToBST(root,mid+1,e,ans);
    return temp;
}


void inorder(BinaryTreeNode* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

BinaryTreeNode* balancedBst(BinaryTreeNode* root) {
    vector<int> ans;
    inorder(root,ans);
    return inorderToBST(root,0,ans.size()-1,ans);
}