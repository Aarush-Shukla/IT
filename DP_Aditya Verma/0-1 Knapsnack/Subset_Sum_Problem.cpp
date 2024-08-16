#include<bits/stdc++.h>
using namespace std;

 int subset_tabulation(vector<int>&arr,int sum){
        int n=arr.size();
        if(n==0 and sum!=0) return 0;
        if(sum==0) return 1;
        vector<vector<int>> dp (n+1,vector<int>(sum+1));
        for(int i=0;i<n+1;i++){
            dp[i][0] = 1;
        }
        for(int j=1;j<sum+1;j++){
            dp[0][j] = 0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    int take = dp[i-1][j-arr[i-1]];
                    int not_take = dp[i-1][j];
                    dp[i][j] = take || not_take;
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }


    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
       return subset_tabulation(arr,sum);
    }
