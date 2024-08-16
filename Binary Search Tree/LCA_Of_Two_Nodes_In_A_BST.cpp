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

//     BinaryTreeNode* LCAinaBST(BinaryTreeNode* root, BinaryTreeNode* P, BinaryTreeNode* Q)
// {
// 	if(root==NULL){
//         return NULL;
//     }
//     if(root->data>P->data && root->data>Q->data){
//         return LCAinaBST(root->left,P,Q);
//     }
//      if(root->data<P->data && root->data<Q->data){
//         return LCAinaBST(root->right,P,Q);
//     }

//     //if not the above two cases then for the remaining cases
//     //root->data>P->data && root->data<Q->data
//     //root->data<P->data && root->data>Q->data
//     // we need to return root only as the final answer
//     return root;
// }


  BinaryTreeNode* LCAinaBST(BinaryTreeNode* root, BinaryTreeNode* P, BinaryTreeNode* Q)
{
while(root!=NULL){
    if(root->data>P->data && root->data>Q->data){
        root=root->left;
    }
     else if(root->data<P->data && root->data<Q->data){
        root=root->right;
    }else{
        return root;
    }
}

}