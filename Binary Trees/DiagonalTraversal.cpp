#include <bits/stdc++.h> 
using namespace std;

//Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// void diagonalelement(Node* root,int level,map<int,vector<int>> &value){
//     if(root==NULL)
//         return;
    
//     value[level].push_back(root->data);
    
//     diagonalelement(root->left,level+1,value);
    
//     diagonalelement(root->right,level,value);
// }
// vector<int> diagonal(Node *root)
// {
//    vector<int> ans;
//    if(root==NULL)
//         return ans;
    
//     map<int,vector<int>> value;
//     diagonalelement(root,0,value);
    
//     for(auto i: value)
//         for(auto j: i.second)
//             ans.push_back(j);
            
//     return ans;
// }


//Approach 2

vector<int> diagonal(Node *root){
queue<Node*> q;
vector<int> ans;
if(root==NULL){
    return ans;
}
q.push(root);
while(!q.empty()){
    Node* temp=q.front();
    q.pop();
    while(temp){
        if(temp->left){
            q.push(temp->left);
        }ans.push_back(temp->data);
        temp=temp->right;
    }
}
return ans;

}

