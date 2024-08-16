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

    BinaryTreeNode* solve(int &i,vector<int> &preorder,int mini,int max){
    //base case
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>max){
        return NULL;
    }
    
    BinaryTreeNode* root=new BinaryTreeNode(preorder[i++]);
    root->left=solve(i,preorder,mini,root->data);
    root->right=solve(i,preorder,root->data,max);
    return root;
}

BinaryTreeNode* preorderToBST(vector<int> &preorder) {
   int mini = INT_MIN;
    int max = INT_MAX;
    int i=0;
    return solve(i,preorder,mini,max);
}