#include<bits/stdc++.h>
using namespace std;

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
          vector<vector<int>> dp(n+1,vector<int>(m+1));
 
    //Base Case

for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){

        dp[i][0]=0;
        dp[0][j]=0;

    }
}

//Choice Diagram

for(int i=1;i<n+1;i++){
    for(int j=0;j<m+1;j++){

        if(S1[i-1]==S2[j-1]){
        dp[i][j] = 1+dp[i-1][j-1];
        }
         else{
        dp[i][j] = 0;
        }
    }
}
int maxi=0;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            
              maxi= max(dp[i][j],maxi); 
        }
    }
    return maxi;
}