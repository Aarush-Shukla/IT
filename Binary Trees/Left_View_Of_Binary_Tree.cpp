#include <bits/stdc++.h> 
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void solve(vector<int> &ans,Node *root,int level){
    //base case
    if(root==NULL){
        return ;
    }
    //we entered into a new level
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solve(ans,root->left,level+1);
    solve(ans,root->right,level+1);
    
}

vector<int> leftView(Node *root)
{
  vector<int> ans;
  solve(ans,root,0);
  return ans;
}