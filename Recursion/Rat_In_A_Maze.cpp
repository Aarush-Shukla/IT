// void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> &vis,
//     string move, vector<int> &di, vector<int> &dj)
//     {
//         if(i == n-1 && j == n-1)
//         {
//             ans.push_back(move);
//             return;
//         }
//         string s = "DLRU";
//         for(int idrow = 0; idrow < 4; idrow++)
//         {
//             int nerowti = i + di[idrow];
//             int nerowtj = j + dj[idrow];
//             // check is nerowt cell is within the boundarcol
//             // check if it is not alreadcol visisted
//             // check if cell is 1 and not 0.
//             if(nerowti >= 0 && nerowti < n && nerowtj >= 0 && nerowtj < n && !vis[nerowti][nerowtj] && m[nerowti][nerowtj])
//             {
//                 vis[i][j] = 1;
//                 solve(nerowti, nerowtj, m, n, ans, vis, move + s[idrow], di, dj);
//                 vis[i][j] = 0;
//             }
//         }
//     }
//     vector<string> findPath(vector<vector<int>> &m, int n) {
//         vector<string> ans;
//         vector<vector<int>> vis(n, vector<int>(n, 0));
//         vector<int> di = {+1, 0, 0, -1};
//         vector<int> dj = {0, -1, +1, 0};
//         if(m[0][0] == 1) solve(0, 0, m, n, ans, vis, "", di, dj);
//         return ans;
//     }
#include <bits/stdc++.h> 
using namespace std;

bool isSafe(vector<vector<int>>& m,int n,int row,int col,vector<vector<int>> visited,string output,vector<string>& ans){
    if((row>=0 && row<n) && (col>=0 && col<n) && (visited[row][col]==0) && (m[row][col]==1)){
        return true;
    }else{
        return false;
    }
}

void solve(vector<vector<int>>& m,int n,int row,int col,vector<vector<int>> visited,string output,vector<string>& ans){
    //Base Case
    if(row==n-1 && col==n-1){
        ans.push_back(output);
        return;
    }
    visited[row][col]=1;
    //choices- D,L,U,R
    
    //Down
    int newrow=row+1;
    int newcol=col;
    if(isSafe(m,n,newrow,newcol,visited,output,ans)){
        output.push_back('D');
        solve(m,n,newrow,newcol,visited,output,ans);
        output.pop_back();
    }
    //Left
    newrow=row;
    newcol=col-1;
    if(isSafe(m,n,newrow,newcol,visited,output,ans)){
        output.push_back('L');
        solve(m,n,newrow,newcol,visited,output,ans);
        output.pop_back();
    }
    
    //Up
    newrow=row-1;
    newcol=col;
    if(isSafe(m,n,newrow,newcol,visited,output,ans)){
        output.push_back('U');
        solve(m,n,newrow,newcol,visited,output,ans);
        output.pop_back();
    }
    
    //Right
    newrow=row;
    newcol=col+1;
    if(isSafe(m,n,newrow,newcol,visited,output,ans)){
        output.push_back('R');
        solve(m,n,newrow,newcol,visited,output,ans);
        output.pop_back();
    }
    
    
    visited[row][col]=0;
}
    
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;
        string output="";
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        int srcrow=0;
        int srccol=0;
        solve(m,n,srcrow,srccol,visited,output,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }