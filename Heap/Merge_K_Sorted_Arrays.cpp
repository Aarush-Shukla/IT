#include <bits/stdc++.h> 
using namespace std;

class node{
    public:
           int data;
           int i;
           int j;

     node(int data,int row,int col){
         this->data=data;
         i=row;
         j=col;
     }      
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data ;
    }
};


// Approach-( T.C-O(N*K(log K)), S.C-(O(N*K)))

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*,vector<node*>,compare> minHeap;// S.C-(O(K))

    //step1- push the first elements of all the arrays(T.C-(O(K logK)))
    for(int i=0;i<k;i++){
          node* temp=new node(kArrays[i][0],i,0);
          minHeap.push(temp);
        }
 
    //step2- jo element aaye hai minheap mai uska minimum data wala element kisi vector mai store karate jana hai
    
    vector<int> ans;//S.C-(O(N*K))
    // T.C-O(N*K(log K))
    while(!minHeap.empty()){
        node* temp=minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();


        int i=temp->i;
        int j=temp->j;
    //step3- poora array traverse karo aur sabko minHeap mai daalte jao 
        if(j+1<kArrays[i].size()){
            node* next=new node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }

    }
    return ans;

}