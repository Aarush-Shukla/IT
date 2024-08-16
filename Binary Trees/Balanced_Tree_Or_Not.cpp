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



//     //Approach 1- T.C-(O(N^2)) as we are using O(N) for balanced funxcction and O(N) for height function

//  int height(Node* node){
//         //base case
//         if(node==NULL){
//             return 0;
//         }
//         int left=height(node->left);
//         int right=height(node->right);
//         int ans=max(left,right)+1;
//         return ans;
//     }
    
//     //Function to check whether a binary tree is balanced or not.
//     bool isBalanced(Node *root)
//     {
//       //base case
//       if(root==NULL){
//           return true;
//       }
//       bool left=isBalanced(root->left);
//       bool right=isBalanced(root->right);
//       bool diff= abs(height(root->left)-height(root->right))<=1;
//       if(left && right && diff){
//           return true;
//       }else{
//           return false;
//       }
//     }




//Approach 2 - T.C-O(N)

pair<bool,int> isBalancedFast(Node *root){
      pair<bool,int> ans;
      //base case
      if(root==NULL){
           pair<bool,int> p= make_pair(true,0);
          return p;
      }
      
      pair<bool,int> left=isBalancedFast(root->left);
      pair<bool,int> right=isBalancedFast(root->right);
      
      bool leftAns=left.first;
      bool rightAns=right.first;
      bool diff= abs(left.second-right.second)<=1;
      ans.second=max(left.second,right.second)+1;
      if(leftAns && rightAns && diff){
          ans.first=true;
      }else{
          ans.first=false;
      }
      return ans;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
      return isBalancedFast(root).first;
    }

