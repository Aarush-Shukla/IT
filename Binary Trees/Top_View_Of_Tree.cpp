#include <bits/stdc++.h> 
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

  vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        map<int,int> topNode;
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            q.pop();
            Node* frontNode=temp.first;
            int hd=temp.second;
            
            if(topNode.find(hd)==topNode.end()){
                topNode[hd]= frontNode->data;
                }
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }   
             if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            } 
        }
        
        for(auto i:topNode){
           ans.push_back(i.second);
            
        }
        
        return ans;
    }

//Approach 2 - used same code as vertical order traversal but instead of pushing multiple node for a hd, we create a 1-1 mapping between hd and levelwise nodes and use break statement for allowing only the first element to push in
    void traverse(Node* node, map<int,map<int,multiset<int>>> &ds, int vertical, int level){
    if(node==NULL) return;
        
    ds[vertical][level].insert(node->data);
        
    traverse(node->left,ds,vertical-1,level+1);
    traverse(node->right,ds,vertical+1,level+1);
}

vector<int> getTopView(Node* root) {
    map<int,map<int,multiset<int>>> ds;
    traverse(root,ds,0,0);
    vector<int> ans;
    for(auto i:ds){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
                break;
            }
            break;
        }
    }
    return ans;
}