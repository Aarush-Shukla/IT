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

// Approach 1- T.C-(O(M+N)) , S.C-(O(M+N))

// void inorder(BinaryTreeNode *root,vector<int> &bst){
//  if(root==NULL){
//      return;
//  }
//  inorder(root->left,bst);
//  bst.push_back(root->data);
//  inorder(root->right,bst);
// }

// vector<int> MergeArray(vector<int> &a,vector<int> &b){
//     int i=0;
//     int j=0;
//     int k=0;
//     vector<int> ans(a.size()+b.size());
    
//     while(i<a.size() && j<b.size()){
//         if(a[i]<b[j]){
//         ans[k++]=a[i];
//         i++;
//         }else{
//             ans[k++]=b[j];
//             j++;
//         }
//     } 
//  while(i<a.size()){
//        ans[k++]=a[i];
//        i++;
//     }
// while(j<b.size()){
//        ans[k++]=b[j];
//        j++;
//     }
//     return ans;
// }

// BinaryTreeNode *inorderToBST(vector<int> &mergedArrays,int s,int e){
//     //base case
//     if(s>e){
//      return NULL;
//     }
//     int mid=s+(e-s)/2;
//     BinaryTreeNode *temp=new BinaryTreeNode(mergedArrays[mid]);
//     temp->left=inorderToBST(mergedArrays,s,mid-1);
//     temp->right=inorderToBST(mergedArrays,mid+1,e);
//     return temp;

// }


// BinaryTreeNode *mergeBST(BinaryTreeNode *root1, BinaryTreeNode *root2){
//     // step1-finding inorder traversal of both BST
//     vector<int> bst1;
//     vector<int> bst2;
//     inorder(root1,bst1);
//     inorder(root2,bst2);

//     // step2- merge the two inorder arrays
//     vector<int> mergedArrays=MergeArray(bst1,bst2);
//     //step3- convert the merged inorder to a BST
//     int s=0;
//     int e=mergedArrays.size()-1;
//     return inorderToBST(mergedArrays,s,e);
// }


// Approach 2- T.C-(O(M+N)) , S.C-(O(H1+H2))

//converted a BST into sorted DLL
void BSTIntoSortedDLL(BinaryTreeNode *root,BinaryTreeNode* &head){
    //base case
    if(root==NULL){
        return;
    }

    BSTIntoSortedDLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    
    
    BSTIntoSortedDLL(root->left,head);
}

//Merge two sorted LL
BinaryTreeNode* MergeTwoSortedDLL(BinaryTreeNode* head1,BinaryTreeNode* head2){

BinaryTreeNode* head=NULL;
BinaryTreeNode* tail=NULL;
while(head1!=NULL && head2!=NULL){
    if(head1->data < head2->data){
        if(head==NULL){
           head=head1;
           tail=head1;
           head1=head1->right;
        }else{
           tail->right=head1;
           head1->left=tail;
           tail=head1;
           head1=head1->right;
        }

    }else{
          
           if(head==NULL){
           head=head2;
           tail=head2;
           head2=head2->right;
        }else{
           tail->right=head2;
           head2->left=tail;
           tail=head2;
           head2=head2->right;
        }

    }
}


while(head1!=NULL){
           tail->right=head1;
           head1->left=tail;
           tail=head1;
           head1=head1->right;
}

while(head2!=NULL){
           tail->right=head2;
           head2->left=tail;
           tail=head2;
           head2=head2->right;
}

return head;

}

//covert sorted DLL into BST
//find n
int COUNT(BinaryTreeNode* head){
int cnt=0;
BinaryTreeNode* temp=head;
while(temp!=NULL){
    cnt++;
    temp=temp->right;
}
return cnt;
}

BinaryTreeNode* ConvertDLLIntoBST(BinaryTreeNode* &head,int n){
//base case
if(n<=0 || head==NULL){
    return NULL;
}

BinaryTreeNode* left= ConvertDLLIntoBST(head,n/2);

BinaryTreeNode* root=head;
root->left=left;
head=head->right;

root->right=ConvertDLLIntoBST(head, n - n/2 -1);

return root;
}
BinaryTreeNode *mergeBST(BinaryTreeNode *root1, BinaryTreeNode *root2){
    //step1- convert a BST into sorted DLL
    BinaryTreeNode* head1=NULL;
    BSTIntoSortedDLL(root1,head1);
    head1->left=NULL;
    
    BinaryTreeNode* head2=NULL;
    BSTIntoSortedDLL(root2,head2);
    head2->left=NULL;

    //step2- merge 2 sorted LL
     BinaryTreeNode* head = MergeTwoSortedDLL(head1,head2);   

//step3- convert SLL into BST
return ConvertDLLIntoBST(head,COUNT(head));

}