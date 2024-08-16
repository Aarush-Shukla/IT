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
    
      Node* solve(int in[],int post[], int &index ,int inorderStart , int inorderEnd , int n){
        if(index<0 || inorderStart>inorderEnd){
            return NULL ;
        }
        
        int element = post[index--] ; // At every interation index is increasing
        Node* root  = new Node(element); 
        int position  = Findposition(in , inorderStart , inorderEnd ,element, n);
        
        
        root->right = solve(in , post , index , position+1 , inorderEnd ,n);
        root->left = solve(in , post , index  , inorderStart , position-1 ,n);
        
        
        return root ;
        
    }

Node *buildTree(int in[], int post[], int n) {
     int postorderindex  = n-1 ;  //Post order is LRN so last element is root .
        Node* ans = solve(in , post , postorderindex , 0  , n-1 , n );
        return ans ;
}



//Approach 2- T.C-(O(N*LOGN)+O(N))) , S.C-(O(N))


  void createMapping(int in[] ,map<int,int> &NodeToIndex,int  n){
        for(int i =0 ; i<n ;i++){
            NodeToIndex[in[i]]=i; 
            }
  }
    
      Node* solve(int in[],int post[], int &index ,int inorderStart , int inorderEnd , int n,map<int,int> &NodeToIndex){
        if(index<0 || inorderStart>inorderEnd){
            return NULL ;
        }
        
        int element = post[index--] ; // At every interation index is increasing
        Node* root  = new Node(element); 
        int position  = NodeToIndex[element];
        
        
        root->right = solve(in , post , index , position+1 , inorderEnd ,n,NodeToIndex);
        root->left = solve(in , post , index  , inorderStart , position-1 ,n,NodeToIndex);
        
        
        return root ;
        
    }

Node *buildTree(int in[], int post[], int n) {
     int postorderindex  = n-1 ;  //Post order is LRN so last element is root .
        map<int,int>NodeToIndex;
        
        createMapping(in,NodeToIndex,n);
        Node* ans = solve(in , post , postorderindex , 0  , n-1 , n ,NodeToIndex);
        return ans ;
}