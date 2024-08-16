// If a BST is given and we need to form minHeap, and its also given that the given tree is CBT then we need to use the advantage of CBT, the advantage is that it would not change its structure, only the values of nodes of BST and the resultant MinHeap would change.


// we got a BST so we could find out inorder of BST which is sorted


// condition for MinHeap-1) N < L , N < R
//                       2) L < R

// Combining the above two condition we get N < L < R which is the condition for preorder                      

// so now we only need to write the code for changing inorder to preorder

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

void inorder(BinaryTreeNode* root, vector<int> &ans)
{
	// base case
	if(root==NULL)
	{
		return;
	}

	inorder(root->left, ans);
	ans.push_back(root->data);
	inorder(root->right, ans);
}

void preorderFill(BinaryTreeNode* root, int &index, vector<int> &ans)
{
	if(root==NULL)
	{
		return;
	}

	root->data=ans[index++];
	preorderFill(root->left, index, ans);
	preorderFill(root->right, index, ans);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> ans;
	inorder(root, ans);

	int index=0;
	preorderFill(root, index, ans);

	return root;
}