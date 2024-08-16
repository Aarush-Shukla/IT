#include <bits/stdc++.h> 
using namespace std;

//Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};

//approach 1
Node* solve(Node* root, int k, int node, vector<int>& path, int &ans){
    if(root == NULL)
     return NULL;
    
    path.push_back(root->data);
    if(root -> data == node)
    return root ;
    
    
  Node* left=  solve(root->left, k, node, path, ans);
  Node* right= solve(root->right, k, node, path, ans);
    
    if(left !=NULL || right !=NULL){
        int size = path.size();
    
    for(int i=0;i<path.size();i++){
        if(path[i] == node){
            int index = i-k;
            
            if(index<0)
                return NULL;
            
            else
                ans = path[i-k];
            }
        }
    }
     else{
    path.pop_back();
         return NULL;
    }
}

int kthAncestor(Node *root, int k, int node)
{  
    if(root->data == node) return -1;
    vector<int> path;
    int ans = -1;
      solve(root, k, node, path, ans);
    return ans;
}




//approach 2

bool solve(Node *root,int &k, int node,int &ans){
    if(root == NULL) return false;
    
    if(root->data == node) return true;
    bool left = solve(root->left,k,node,ans);
    bool right = solve(root->right, k,node,ans);
    
    if(left||right){
        k--;
        if(k==0) ans = root->data;
        return true;
    }
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
     int ans;
    solve(root,k,node,ans);
    if(k>0) return -1;         // If k is greater than required distance b/w nodes.
    return ans;
}