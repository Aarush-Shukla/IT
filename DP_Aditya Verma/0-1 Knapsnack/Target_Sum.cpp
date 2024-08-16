#include<bits/stdc++.h>
using namespace std;


// 1)  We are initialising first column to 1, assuming there is only 1 way to make subset sum equal to 0,  i.e. null subset, BUT this fails if we have 0's as elements of array. If we have a single 0 present in the array, then the subsets will be '{}, {0}' whose sum will be 0. Hence, there can be more than 1 way to make sum==0.
// FIX: Don't initialise the first col to be 1. Everything will be initialized to 0 except the first cell in the table i.e. dp[0][0]=1. AND j will start from 0 instead of 1.

// 2)  In the derived formula, target = (diff+totalSum) / 2, NOTICE that (diff+totalSum) must be even for target to be a whole number, else it's not possible to find a decimal target in subset sum. Hence, we also need to take care of the test cases where it's not possible to partition the array.
// FIX: Check, if it's odd,  there is no way --> if((diff+totalSum)%2 != 0) return 0;

 int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum=0;
        for(auto i: nums) sum+=i;
        if (abs(target) > sum) return 0;  // nums = [10], target = -100
        if((target+sum)%2 != 0) return 0;
        int t=(target+sum)/2;
        //REDUCED: find count of subset with sum equal to t
        vector<vector<int>> dp(n+1, vector<int>(t+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<n+1; i++) {
            for(int j=0; j<t+1; j++) {
                if(nums[i-1] <= j) 
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-nums[i-1]])%1000000007;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][t];


    }