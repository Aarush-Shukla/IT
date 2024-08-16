#include <bits/stdc++.h> 
using namespace std;

//2nd approach (brute force)
  bool isSafe(int col,int row,int n,vector<string> board){
       int duprow=row;
       int dupcol=col;
       while(col>=0 & row>=0){
           if(board[row][col]=='Q') return false;
           row--;
           col--;
       }
        
        row=duprow;
        col=dupcol;

       while(col>=0){
           if(board[row][col]=='Q')return false;
           col--;
       }

        row=duprow;
        col=dupcol;
            
        while(col>=0 & row<n){
           if(board[row][col]=='Q') return false;
           row++;
           col--;
       }
       return true;
   }
   
   
    void solve (int col,int n,vector<string>& board,vector<vector<string>>& ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(col,row,n,board)){
                board[row][col]='Q';
                solve (col+1,n,board,ans);
                board[row][col]='.';

            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i =0; i<n;i++){
            board[i] = s;
        }
        solve (0,n,board,ans);
        return ans;
    }


     //1st approach(optimised)
     
//  void solve (int col,int n,vector<string>& board,vector<vector<string>>& ans,vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal){
//         if(col==n){
//             ans.push_back(board);
//             return;
//         }
//         for(int row=0;row<n;row++){
//         if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
//             board[row][col]='Q';
//             leftRow[row]=1;
//             lowerDiagonal[row+col]=1;
//             upperDiagonal[n-1+col-row]=1;
//             solve (col+1,n,board,ans,leftRow,upperDiagonal,lowerDiagonal);

//             board[row][col]='.';
//             leftRow[row]=0;
//             lowerDiagonal[row+col]=0;
//             upperDiagonal[n-1+col-row]=0;


//         }
           
//         }
//     }
    
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n,'.');
//         for(int i =0; i<n;i++){
//             board[i] = s;
//         }
//         vector<int> leftRow(n,0);
//         vector<int> upperDiagonal(2*n -1,0);
//         vector<int> lowerDiagonal(2*n -1,0);

//         solve (0,n,board,ans,leftRow,upperDiagonal,lowerDiagonal);
//         return ans;
//     }