#include <bits/stdc++.h> 
using namespace std;

 
template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };

void inorder(BinaryTreeNode<int> *root,int &cnt){
    if(root==NULL){
      return;
    }

    //left node
    inorder(root->left,cnt);

    //leaf node
    if(root->left==NULL && root->right==NULL){
       cnt++;
   }

    //right node
    inorder(root->right,cnt);
}


int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt=0;
    inorder(root,cnt);
    return cnt;
}