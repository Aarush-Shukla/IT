#include <bits/stdc++.h> 
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


    void solve(TreeNode* root,vector<int> &ans,int level){
        if(root==NULL){
            return;
        }
        if(level==ans.size())
        ans.push_back(root->val);
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0);
        return ans;
    }



    //For Left Side View

    void solve(TreeNode* root,vector<int> &ans,int level){
        if(root==NULL){
            return;
        }
        if(level==ans.size())
        ans.push_back(root->val);
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0);
        return ans;
    }



    //2nd Method;
    //use break statement for left view while traversing level wise so only first element on that level could only be traversed
    //and for right order view use 1-1 mapping or solve the right subtree first and use break in level order traversal