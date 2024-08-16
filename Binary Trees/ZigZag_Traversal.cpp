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

 //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	
    	if(root==NULL){
    	    return result;
    	}
    	queue<Node*> q;
    	q.push(root);
    	bool leftToRight=true;
    	while(!q.empty()){
    	    
    	    int size=q.size();
    	    vector<int>ans(size);
    	    
    	    //level process
    	    for(int i=0;i<size;i++){
    	        Node* temp= q.front();
    	        q.pop();
    	        
    	        //normal insert or reverse insert
    	        int index= leftToRight ? i : size-i-1;
    	        ans[index]=temp->data;
    	        
    	        if(temp->left){
    	            q.push(temp->left);
    	        }
    	        if(temp->right){
    	            q.push(temp->right);
    	        }
    	    }
    	    //direction change karni hai
    	    leftToRight=!leftToRight;
    	    
    	    for(auto i:ans){
    	        result.push_back(i);
    	    }
    	}
    	
        return result;
    	
    }