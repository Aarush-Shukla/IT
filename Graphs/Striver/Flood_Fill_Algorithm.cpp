#include <bits/stdc++.h>
using namespace std;
  
// //approach1 using dfs; 
// void dfs ( int sr, int sc,vector<vector<int>> &ans, vector<vector<int>>& image, int newColor,int drow[],int dcol[],int initialColor){
//     ans[sr][sc]=newColor;
//     int n=image.size();
//     int m= image[0].size();
//     for(int i=0;i<4;i++){
//         int nrow=sr + drow[i];
//         int ncol=sc + dcol[i];
//         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialColor && ans[nrow][ncol]!=newColor ){
//             dfs(nrow,ncol,ans,image,newColor,drow,dcol,initialColor);
//         }
        
//     }
// }


//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//       vector<vector<int>> ans=image; 
//       int initialColor=image[sr][sc];
//       int drow[]={-1,0,+1,0};
//       int dcol[]={0,+1,0,-1};
//       dfs(sr,sc,ans,image,newColor,drow,dcol,initialColor);
//       return ans;
//     }



//Approach 2 using bfs;

void bfs(vector<vector<int>>&image,vector<vector<int>>&ans,int sr,int sc,int iniColor,int newColor)
    {
        ans[sr][sc] = newColor;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size() && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
                {
                    ans[nrow][ncol] = newColor;
                    q.push({nrow,ncol});
                }
            }
        }
    }

 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        vector<vector<int>>ans = image;
        int iniColor = image[sr][sc];
        bfs(image,ans,sr,sc,iniColor,color);
        return ans;
    }