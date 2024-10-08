#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int M, int V) 
	{ 
        int t[M+1][V+1];
	    
	    t[0][0] = 0;
	    
	    for(int i=1;i<M+1;i++)
	    t[i][0] = 0;
	    
	    for(int j=1;j<V+1;j++)
	    t[0][j] = INT_MAX-1;
	    
	    for(int i=1;i<M+1;i++)
	    {
	        for(int j=1;j<V+1;j++)
	        {
	            if(coins[i-1]<=j)
	            t[i][j] = min(1+t[i][j-coins[i-1]],t[i-1][j]);
	            
	            else
	            t[i][j] = t[i-1][j];
	            
	        }
	    }
	   
	    int ans;
	   if(t[M][V] == INT_MAX-1){
	       ans = -1 ;
	   } else{
	       ans = t[M][V];
	   } 
	    return ans;
	  
	} 
