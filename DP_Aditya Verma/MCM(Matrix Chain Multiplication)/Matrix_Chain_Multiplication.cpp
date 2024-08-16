#include<bits/stdc++.h>
using namespace std;

//Recursive Approach
int solve(int arr[],int i,int j){
    //base condition
    if(i>=j) return 0;
//At i == j the cost is zero not because there's only one element in the array. It'll be because there's no other matrix to which the remaining matrix will be multiplied

// Ex. [10, 20]

// Here i = 1, and j = 1. So, there's only one matrix in the array and no other matrix to which this matrix can be multiplied. So, there will be no multiplication, hence the cost of multiplication becomes zero
   
    int mini=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int tempAns=(solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]));
        mini=min(mini,tempAns);
    }
    return mini;
}

    int matrixMultiplication(int N, int arr[])
    {
        return solve(arr,1,N-1);
    }




// Recursive + Memoization


    int solve(int arr[],int i,int j){

    int dp[102][102];
    memset(dp,-1,sizeof(dp));
    //base condition
    if(i>=j) return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int tempAns=(solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]));
        mini=min(mini,tempAns);
    }
    dp[i][j]=mini;
    return dp[i][j];
}

    int matrixMultiplication(int N, int arr[])
    {
        return solve(arr,1,N-1);
    }






//Tabulation


int n;

     int** dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[n];
        for(int j=0; j<n; j++){
            if(i <= j || i == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = -1;
            }
        }
    }

    int temp;
    int minans;
    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<n; j++){
            int minval = INT_MAX;
            for(int k=i; k<j; k++){
                temp = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                // cout << "i: " << i << " j: " << j << " k: " << k << " mult " << arr[i-1]*arr[k]*arr[j];
                // cout << " dp[i][k]: " << dp[i][k] << " dp[k+1][j]: " << dp[k+1][j] << endl;
                minval = min(temp, minval);
            }
            dp[i][j] = minval;
            // minans = min(dp[i][j], minans);
            // dp[i][j] = dp[i][]
        }
    }


    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[1][n-1];