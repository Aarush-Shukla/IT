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

    void inorder(BinaryTreeNode* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);

}

bool twoSumInBST(BinaryTreeNode* root, int target) {
	vector<int> ans;
    //store inorder->sorted values
    inorder(root,ans);
    //use 2 pointer approach to check if pair exists
    int i=0;
    int j=ans.size()-1;
    while(i<j){
        int sum=ans[i]+ans[j];
        if(target==sum){
            return true;
        }else if(sum>target){
              j--;
        }else{
            i++;
        }
    }
    return false;
}