#include <bits/stdc++.h> 
using namespace std;

  void DFS(vector<vector<int>>& stones, int index, vector<int>& vis) {
       
       int n=stones.size();
        vis[index] = 1;
        
        for(int i = 0; i<n; i++) {
            if(!vis[i] &&
               ((stones[i][0] == stones[index][0]) || (stones[i][1] == stones[index][1]))) {
                DFS(stones, i, vis);
            }
        }
    }
  
    int maxRemove(vector<vector<int>>& stones, int n) {
        vector<int> vis(n, 0);
        
        int c = 0;
        for(int i = 0; i<n; i++) {
            if(vis[i])
                continue;
            DFS(stones, i, vis);
            c++;
        }
        
        return n - c;
    }


