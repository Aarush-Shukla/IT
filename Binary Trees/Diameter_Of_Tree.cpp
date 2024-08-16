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

class Solution {
  public:
   
//     //Approach 1- T.C-(O(N^2)) as we are using O(N) for diameter funxcction and O(N) for height function

//      //Function to find the height of a binary tree.
//     int height(struct Node* node){
//         //base case
//         if(node==NULL){
//             return 0;
//         }
//         int left=height(node->left);
//         int right=height(node->right);
//         int ans=max(left,right)+1;
//         return ans;
//     }
   
   
//    // Function to return the diameter of a Binary Tree.
//     int diameter(Node* root) {
//           //base case
//         if(root==NULL){
//             return 0;
//         }
//         int op1=diameter(root->left);
//         int op2=diameter(root->right);
//         int op3= height(root->left)+height(root->right)+1;
        
//         int ans=max(op1,max(op2,op3));
//         return ans;
//     }




//Approach 2 - T.C-O(N)

pair<int,int> DiameterFast(Node* root){
    //base case
    if(root==NULL){
        pair<int,int> p = make_pair(0,0); //(diameter,height)
        return p;
    }
    
    pair<int,int> left= DiameterFast(root->left);
    pair<int,int> right=DiameterFast(root->right);
    
    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;
    
    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}


   // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
          //base case
      return DiameterFast(root).first;
    }

};