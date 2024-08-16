#include <bits/stdc++.h> 
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;

  Node(int x){
    data=x;
    left=NULL;
    right= NULL;
}
};

//Approach 1 T.C-(O(N^2)) , S.C(O(1))

int Findposition(int in[] ,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(in[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }
    
Node* solve(int in[],int pre[], int &index ,int inorderStart , int inorderEnd , int n){
        if(index>=n || inorderStart>inorderEnd){
            return NULL ;
        }
        
        int element = pre[index++] ; // At every interation index is increasing
        Node* root  = new Node(element); 
        int position  = Findposition(in , inorderStart , inorderEnd ,element, n);
        
        root->left = solve(in , pre , index  , inorderStart , position-1 ,n);
        root->right = solve(in , pre , index , position+1 , inorderEnd ,n);
        
        return root ;
        
    }
    
Node* buildTree(int in[],int pre[], int n)
    {
            
        int preorderindex  = 0 ;  //Pre order is NLR so First element is root .
        Node* ans = solve(in , pre , preorderindex , 0  , n-1 , n );
        return ans ;
        
    }



    //Approach 2- T.C-(O(N*LOGN)+O(N))) , S.C-(O(N))


   void createMapping(int in[] ,map<int,int> &NodeToIndex,int  n){
        for(int i =0 ; i<n ;i++){
            NodeToIndex[in[i]]=i; 
            }
  }
    
      Node* solve(int in[],int pre[], int &index ,int inorderStart , int inorderEnd , int n,map<int,int> &NodeToIndex){
        if(index>=n || inorderStart>inorderEnd){
            return NULL ;
        }
        
        int element = pre[index++] ; // At every interation index is increasing
        Node* root  = new Node(element); 
        int position  = NodeToIndex[element];
        
        
        
        root->left = solve(in , pre , index  , inorderStart , position-1 ,n,NodeToIndex);
        root->right = solve(in , pre , index , position+1 , inorderEnd ,n,NodeToIndex);
        
        return root ;
        
    }
    
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
       int preorderindex  = 0 ;  //Pre order is NLR so first element is root .
        map<int,int>NodeToIndex;
        
        createMapping(in,NodeToIndex,n);
        Node* ans = solve(in , pre , preorderindex , 0  , n-1 , n ,NodeToIndex);
        return ans ;
    }