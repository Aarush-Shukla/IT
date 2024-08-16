#include <bits/stdc++.h> 
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

pair<bool,int> isSumTreeFast(Node* root){
        pair<bool,int> ans;
        //base case
        if(root==NULL){
             pair<bool,int> p= make_pair(true,0);
             return p;
        }
        if(root->left==NULL && root->right==NULL){
              pair<bool,int> p= make_pair(true,root->data);
             return p;
        }
        

    pair<bool,int> left=isSumTreeFast(root->left);
    pair<bool,int> right=isSumTreeFast(root->right);
    
    bool leftAns=left.first;
    bool rightAns=right.first;
    bool cond= root->data==left.second+right.second;
    
    if(leftAns && rightAns && cond){
        ans.first=true;
        ans.second=2*root->data;
    }else{
        ans.first=false;
    }
    return ans;
        
    }
    
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }