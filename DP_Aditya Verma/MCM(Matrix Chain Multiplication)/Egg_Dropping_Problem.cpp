#include<bits/stdc++.h>
using namespace std;

 // Recursion
    // int eggDropRec(int n, int k){
    //     if(k == 0 || k == 1)
    //         return k;
    //     if(n == 1)
    //         return k;
        
        
    //     int mn = INT_MAX, x, res;
        
    //     for(x = 1; x <= k; x++){
    //         res = max(eggDrop(n-1, x-1), eggDrop(n, k-x));
            
    //         mn = min(mn, res);
    //     }
        
    //     return mn+1;
    // }
    
    // Memoization
    // int eggDropMemo(int n, int k, vector<vector<int>> &dp){
    //     if(k == 0 || k == 1)
    //         return k;
    //     if(n == 1)
    //         return k;
        
    //     if(dp[n][k] != -1) return dp[n][k];
        
    //     int mn = INT_MAX, x, res;
        
    //     for(x = 1; x <= k; x++){
    //         res = max(eggDropMemo(n-1, x-1, dp), eggDropMemo(n, k-x, dp));
            
    //         mn = min(mn, res);
    //     }
        
    //     return dp[n][k] = mn+1;
    // }
    
    // Memoization optimized
    int eggDropMemoOptmized(int n, int k, vector<vector<int>> &dp){
         if(k == 0 || k == 1)
            return k;
        if(n == 1)
            return k;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int mn = INT_MAX, x;
        
        for(x = 1; x <= k; x++){
            
            int low, high = 0;
            
            if(dp[n-1][x-1] != -1)
                low = dp[n-1][x-1];
            else
                low = eggDropMemoOptmized(n-1, x-1, dp);
                
            if(dp[n][k-x] != -1)
                high = dp[n][k-x];
            else
                high = eggDropMemoOptmized(n, k-x, dp);
                
            int temp = 1+max(low, high);
            
            mn = min(mn, temp);
        }
        
        return dp[n][k] = mn;
    }
    
    // Tabulation
    // int eggDropTab(int n, int k){
    //     int dp[k+1][n+1];
    //     for(int i = 1; i <= n; i++){
    //         dp[1][i] = 1;
    //         dp[0][i] = 0;
    //     }
        
    //     for(int j = 1; j <= k; j++)
    //         dp[j][1] = j;
        
    //     for(int i = 2; i <= k; i++){
    //         for(int j = 2; j <= n; j++){
                
    //             dp[i][j] = INT_MAX;
    //             for(int x = 2; x <= i; x++){
    //                 dp[i][j] = min(dp[i][j], 1 + max(dp[x-1][j-1], dp[i-x][j]));
    //             }
    //         }
    //     }
        
    //     return dp[k][n];
    // }
    
   
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // n --> eggs
        // k --> floors
        
        // Recrusion
        // return eggDropRec(n, k);
        
        // Memoization
        // vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        // return eggDropMemo(n, k, dp);
        
        // Optimized memoization
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return eggDropMemoOptmized(n, k, dp);
        
        // Tabulation
        // return eggDropTab(n, k);
    }

