#include <bits/stdc++.h>
using namespace std;

//BFS Approach

   int numberOfEnclaves(vector<vector<int>> &grid) {
        queue <pair<int,int>> q; 
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m] = {0}; 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
    }
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        while(!q.empty() ){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
              // check for top, right, bottom, left 
        for(int i = 0;i<4;i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
                }
            }
        }
        
            // if unvisited 1 then count them
        int count=0;
        for(int i = 0;i<n;i++) {
            for(int j= 0 ;j<m;j++) {
                if(!vis[i][j] && grid[i][j] == 1) 
                    count++; 
            }
        }
        
        return count;
        
    }