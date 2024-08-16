#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* Mapping(Node* root,int target,map<Node*,Node*>&nodeToParent){
     Node* res=NULL;
     queue<Node*>q;
     q.push(root);
     nodeToParent[root]=NULL;
     while(!q.empty()){
         Node* front=q.front();
         q.pop();
         if(front->data==target){
             res=front;
         }
         if(front->left){
             nodeToParent[front->left]=front;
             q.push(front->left);
         }
          if(front->right){
             nodeToParent[front->right]=front;
             q.push(front->right);
         }
     }
     
     return res;
 }
 
 int burnTime(Node* root, map<Node*,Node*>&nodeToParent){
     int ans=0;
        queue<Node*>q;
        q.push(root);
        
         
        map<Node*,bool>visited;
        visited[root]=true;
       
        while(!q.empty()){
            bool flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                if(front->left &&!visited[front->left]){
                    flag=1;
                    visited[front->left]=true;
                    q.push(front->left);
                }
                if(front->right &&!visited[front->right]){
                    flag=1;
                    visited[front->right]=true;
                    q.push(front->right);
                }
                if(nodeToParent[front] &&!visited[nodeToParent[front]]){
                    flag=1;
                    visited[nodeToParent[front]]=true;
                    q.push(nodeToParent[front]);
                }
                
            }
            if(flag==1){
                ans++;
            }
        }
     
    return ans;
 }
  
  
    int minTime(Node* root, int target) 
    {
        //algo:
        // 1)Create a nodeToParent Map
        // 2)Find the target node
        // 3)burn the tree in min time
        
        map<Node*,Node*>nodeToParent;
        Node* targetnode= Mapping(root,target,nodeToParent);
        int ans=burnTime(targetnode,nodeToParent);
        return ans;
    }