 #include <bits/stdc++.h> 
using namespace std;
 
 // Definition for a binary tree node.
  struct TreeNode {
      long long val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 
 void solve(TreeNode* root, long long targetSum, long long &count, vector<long long> path) {
        //base case
        if(root == NULL)
            return ;
        
        path.push_back(root->val);
        
        //left
        solve(root->left, targetSum, count, path);
        //right
        solve(root->right, targetSum, count, path);
        
        //check for K Sum
        
        long long size = path.size();
        long long sum = 0;
        for(long long i = size-1; i>=0; i--)  {
            sum += path[i];
            if(sum == targetSum)
                count++;
        }
        
        path.pop_back();
    }

    long long pathSum(TreeNode* root, long long targetSum) {
         vector<long long> path;
        long long count = 0;
        solve(root, targetSum, count, path);
        return count;
    }