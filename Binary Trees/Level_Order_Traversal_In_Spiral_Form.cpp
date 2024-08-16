#include<bits/stdc++.h>
using namespace std;

// Node class
class Node{
public:
    int val;
    Node *left, *right;
    
    // Constructor
    Node(int Val){
        val = Val;
        left = nullptr;
        right = nullptr;
    }
};
// Function to find the height of the tree.
int height(Node *root){
    // Base condition to check if
    // root is nullptr.
    if (root == nullptr)
        return 0;
    
    // Finding the height of the left subtree.
    int left = height(root->left);
    // Finding the height of the right subtree.
    int right = height(root->right);

    return 1 + max(left, right);

}

// Recursion function to print the ith level.
void printLevel(Node *root, int level, bool ltr){
    // Base condition to check if root itself is nullptr.
    if (root == nullptr)
        return;
    
    // Base condition to checl if the level is 1
    if (level == 1){
        cout << root->val <<" ";
        return;
    }

    // If it is required to print left to 
    // right fashion.
    if (ltr){
        // Recurring for the left subtree.
        printLevel (root->left, level - 1, ltr);

        // Recurring for the right subtree
        printLevel (root->right, level - 1, ltr);
    } else{
        // Recurring for the right subtree
        printLevel (root->right, level - 1, ltr);

        // Recurring for the left subtree.
        printLevel (root->left, level - 1, ltr);
    }
}
// Function to print nodes in spiral order.
void printSpiral(Node *root){
    // Finding height of the tree.
    int h = height(root);

    // Declaring boolean variable ltr.
    bool ltr = true;

    // Iterating from i = 1 to i = h;
    for (int i = 1; i <= h; i++){
        // Calling printLevel to print the
        // i^th level.
        printLevel(root, i, ltr);

        // Flipping the ltr
        ltr = !ltr;
    }

}

// Main function
int main(){
    // Constructing the following tree - 
    //           1
    //         /  \
    //        /    \
    //       2      3
    //      / \    / \
    //     /   \  /   \
    //    4    5 6    7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
	
	cout << "The Spiral order traversal of the tree is -" << endl;
    // Calling 'spiralOrder' function to 
    // print nodes in spiral order fashion.
    printSpiral(root);
}



/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


// //Function to return a list containing the level order traversal in spiral form.
// vector<int> findSpiral(Node *root)
// {
//     vector<int> ans;
//     deque<pair<int,Node*>> dq;
//     dq.push_front({0,root});
//     while(!dq.empty()){
//         int curLevel=dq.front().first;
//         int size=dq.size();
//         for(int i=0;i<size;i++){
//             // odd level
//             // operate like normal level order traversal
//             if(curLevel&1){
//                 Node *cur=dq.front().second; dq.pop_front();
//                 ans.push_back(cur->data);
//                 if(cur->left) dq.push_back({curLevel+1,cur->left});
//                 if(cur->right) dq.push_back({curLevel+1,cur->right});
//             }
//             // even level, start operating from back and also reverse
//             // the left child, right child order 
//             else{
//                 Node *cur=dq.back().second; dq.pop_back();
//                 ans.push_back(cur->data);
//                 if(cur->right) dq.push_front({curLevel+1,cur->right});
//                 if(cur->left) dq.push_front({curLevel+1,cur->left});
//             }
//         }
//     }
//     return ans;
// }