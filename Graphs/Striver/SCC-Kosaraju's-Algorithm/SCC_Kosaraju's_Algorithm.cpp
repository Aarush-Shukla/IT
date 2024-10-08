#include<bits/stdc++.h>
using namespace std;


class Solution
{
        
	public:
 
  	void dfs(int index  , vector<int> &vis , vector<vector<int>>& adj , stack<int>&st){
	    
	    vis[index] = 1;
	    for(auto it : adj[index]){
	        if(!vis[it]){
	            dfs(it , vis , adj , st);
	        }
	    }
	    st.push(index);
	}
	
	void dfs1(int index  , vector<int> &vis , vector<int>adjTranspose[] ){
	    vis[index] = 1;
	    for(auto it : adjTranspose[index]){
	        if(!vis[it]){
	            dfs1(it , vis , adjTranspose);
	        }
	    }
	}

	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
     stack<int> st;
        vector<int> vis(V , 0);
        vector<int> adjTranspose[V];
       
        
        for(int i = 0 ; i<V  ;i++){
            if(!vis[i]){
                dfs( i , vis , adj , st);
            }
        }
        
        for(int i = 0 ; i<V ; i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                adjTranspose[it].push_back(i);
            }
        }
        
        int scc = 0;
        while(!st.empty()){
            int t = st.top();
            st.pop();
            if(!vis[t]){
                dfs1(t , vis , adjTranspose);
                scc++;
            }
        }
        return scc;
    }
};

