#include <bits/stdc++.h>
using namespace std;

//Aproach 1 

// I think there is no need. You can initialize dp[0][0]=1 and dp[0][1..sum]=0
// Now you have only 1 row initialized. Now if you run the dp from i=1..n and j=*0*..sum
// If we run the j loop from 0..sum instead of 1..sum, it will count number of subsets for 0 too.

// If you still don't understand *how*:
// In first loop we are at _ element.(sum=0)
// 1 0 0 0 0 0 0 0 0 0 
// _

// Now we apply the condition. if(0<=sum) dp[1][0] = dp[0][0] + dp[0][0-0] which is dp[1][0] = 1+1 i.e, 2.
// One observation is that you are adding the element i.e, above the current element twice.
// Repeat same for all rows in current column.

// int perfectSum(int arr[], int n, int sum)
// 	{
//         int t[n+1][sum+1];
//         memset(t,0,sizeof(t));
//         int cnt=1;
//         t[0][0]=1;
    
//         int mod= (int)1e9+7;
//         for(int i=1;i<n+1;++i)
//         {
//             for(int j=0;j<sum+1;++j)                                            
//             {
//                 if(arr[i-1]<=j)
//                 {
//                     t[i][j]=(t[i-1][j]+t[i-1][j-arr[i-1]])%mod;
//                 }
//                 else if(arr[i-1]>j)
//                 {
//                     t[i][j]=t[i-1][j];
//                 }
//             }
//         }
//         return t[n][sum];
            
// 	}






//Approach 2

// The problem is, that initializing the entire column with 1 will work only if the input array has all non-zero elements. 
// As me and a few others have pointed out, the method fails when the input array has any zeros. 
// For eg: n=3, sum=0.
// We can have a set here as {0,1,2}, so there'll be subsets of {} and {0} possible hence count will be 2. This is true for multiple other input arrays where actually count >1 for sum=0, but we initialized count=1 for all input arrays when sum=0. 

// Here's a small fix I found to the issue:

// We initialize the first column of the array acc to the formula: 2 ^ (no of zeros in the array at that size).

// Hence, for eg: arr={0,0,1,0}, sum=0
// For n=0, value will be 2^0 = 1, i.e {} 
// For n=1, value will be 2^1 = 2, i.e. {} and {0}
// For n=2, value will be 2^2= 4, i.e. {}, {0}, {0} and {0,0} 
// For n=3, value will be 2^2 = 4, i.e. {}, {0], {0}, and {0,0}
// For n=4, value will be 2^3 = 8 i.e. {}, .............., {0,0,0}

// Reason: 
// In the sum of subset problem, we simply needed to return whether or not a set exists for sum=0, which was always True as empty set {} was always existing. Here, we need to return count of subsets for sum=0 (for first column), which will include all possible subsets in the array which add up to 0.

int perfectSum(int arr[], int n, int sum)
	{
        int t[n+1][sum+1];
        memset(t,0,sizeof(t));
        int cnt=1;
        t[0][0]=1;
        for(int i=0;i<n;++i)
        {
            if(arr[i]==0)
            {
                cnt*=2;
                t[i+1][0]=cnt;
            }
            else
            {
                t[i+1][0]=t[i][0];
            }
            
        }
        int mod= (int)1e9+7;
        for(int i=1;i<n+1;++i)
        {
            for(int j=1;j<sum+1;++j)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j]=(t[i-1][j]+t[i-1][j-arr[i-1]])%mod;
                }
                else if(arr[i-1]>j)
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
            
	}







