#include <bits/stdc++.h> 
using namespace std;


//Approach 1- T.C(O(N)),S.C(O(N))
bool knows(vector<vector<int> >& M,int a,int b,int n){
      if(M[a][b]==1){
          return true;
      }else{
          return false;
      }
  }
  
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        //step1- pushing all elements into stack
        for(int i=0;i<n;i++){
            s.push(i);
        }
        //step2- getting the potential celebrity from stack by comparing them
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        int ans=s.top();
        //step3- the ans is potential celebrity
        //so verify it
        
        //rowcheck
        bool rowCheck=false;
        int zeroCount=0;
        
        for(int i=0;i<n;i++){
            if(M[ans][i]==0){
                zeroCount++;
            }
        }
        if(zeroCount==n){
            rowCheck=true;
        }
        
        //colCheck
        bool colCheck=false;
        int oneCount=0;
        
        for(int i=0;i<n;i++){
            if(M[i][ans]==1){
                oneCount++;
            }
        }
        if(oneCount==n-1){
            colCheck=true;
        }
        
        if(rowCheck==true && colCheck==true){
            return ans;
        }else{
            return-1;
        }
        
    }


    //Approach 2- T.C(O(N)),S.C(O(1))
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int start =0, end = n-1;
        
        while(start<end){
            if(M[start][end]==0){
                end--;
            }
            else{
                start++;
            }
        }
        
        int candidate = start;
        
        int zeroCount=0;
        for(int i=0;i<n;i++){
            if(M[candidate][i]!=0) return -1;
            
            if(i!=start && M[i][candidate]!=1) return -1;
        }
        
        
        
        return candidate;
    }