/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST

void inorder(Node* root, vector<float>&v){
      
      if(root == NULL)return;
      
      inorder(root->left, v);
      v.push_back(root->data);
      inorder(root->right, v);

      }

float findMedian(struct Node *root)
{
        vector<float>v;
        inorder(root, v);
        int z = v.size();
        if(z%2!=0){
            return v[z/2];
        }else{
            return (v[z/2]+v[z/2-1])/2;
        }
}
