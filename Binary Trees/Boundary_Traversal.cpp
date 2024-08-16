#include <bits/stdc++.h> 
using namespace std;

//A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; 



void leftTraversal(Node* root,vector <int> &ans){
    if (root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }//sahi order mai chahiye the elements toh apan pehle push back kiye hai
    ans.push_back(root->data);
    if(root->left){
        leftTraversal(root->left,ans);
    }else{
        leftTraversal(root->right,ans);
    }
}


void leafNode(Node *root,vector <int> &ans){
    if(root==NULL){
        return;
    }
    
    if (root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
   
    leafNode(root->left,ans);
    leafNode(root->right,ans);
    
}

void rightTraversal(Node *root,vector <int> &ans){
    if (root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    
    if(root->right){
        rightTraversal(root->right,ans);
    }else{
        rightTraversal(root->left,ans);
    }//reverse order mai chahiye the elements toh apan baad mai push_back lagaye hai
    ans.push_back(root->data);
}

    vector <int> boundary(Node *root){
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        
        //left side traversal without taking the leaf node
        leftTraversal(root->left,ans);
        
        //leaf Nodes
        //Left Subtree
        leafNode(root->left,ans);
        //right subtree
        leafNode(root->right,ans);
        
        //right side traversal without taking the leaf node
        rightTraversal(root->right,ans);
        
        return ans;
    }