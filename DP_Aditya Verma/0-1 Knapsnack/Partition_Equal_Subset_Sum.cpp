// Partition problem using recursion:

#include <bits/stdc++.h>
using namespace std;
 
bool isSubsetSum(int arr[], int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
 
    // If last element is greater than sum, then
    // ignore it
    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);
 
    /* else, check if sum can be obtained by any of
        the following
        (a) including the last element
        (b) excluding the last element
    */
    return isSubsetSum(arr, n - 1, sum)
           || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}
 
// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
bool findPartiion(int arr[], int n)
{
    // Calculate sum of the elements in array
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    // If sum is odd, there cannot be two subsets
    // with equal sum
    if (sum % 2 != 0)
        return false;
 
    // Find if there is subset with sum equal to
    // half of total sum
    return isSubsetSum(arr, n, sum / 2);
}




// Partition problem using memoization:

#include <bits/stdc++.h>
using namespace std;
 
// A utility function that returns true if there is
// a subset of arr[] with sun equal to given sum
bool isSubsetSum(int arr[], int n, int sum,
                 vector<vector<int> >& dp)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
 
    // return solved subproblem
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }
 
    // If last element is greater than sum, then
    // ignore it
    if (arr[n - 1] > sum)
        return dp[n][sum]= isSubsetSum(arr, n - 1, sum, dp);
 
    /* else, check if sum can be obtained by any of
        the following
        (a) including the last element
        (b) excluding the last element
    */
    // also store the subproblem in dp matrix
    return dp[n][sum]
           = isSubsetSum(arr, n - 1, sum, dp)
             || isSubsetSum(arr, n - 1, sum - arr[n - 1],
                            dp);
}
 
// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
bool findPartiion(int arr[], int n)
{
    // Calculate sum of the elements in array
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    // If sum is odd, there cannot be two subsets
    // with equal sum
    if (sum % 2 != 0)
        return false;
 
    // To store overlapping subproblems
    vector<vector<int> > dp(n + 1,
                            vector<int>(sum + 1, -1));
 
    // Find if there is subset with sum equal to
    // half of total sum
    return isSubsetSum(arr, n, sum / 2, dp);
}





// Partition problem using dynamic programming:

#include <bits/stdc++.h>
using namespace std;
 
// Returns true if arr[] can be partitioned
// in two subsets of equal sum, otherwise false
bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;
 
    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    bool dp[sum / 2 + 1][n + 1];
 
    // initialize top row as true
    for (i = 0; i <= n; i++)
        dp[0][i] = true;
 
    // initialize leftmost column,
    // except part[0][0], as 0
    for (i = 1; i <= sum / 2; i++)
        dp[i][0] = false;
 
    // Fill the partition table in bottom up manner
    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= arr[j - 1])
                dp[i][j] = dp[i][j]
                             || dp[i - arr[j - 1]][j - 1];
        }
    }
 
    /* // uncomment this part to print table
    for (i = 0; i <= sum/2; i++)
    {
    for (j = 0; j <= n; j++)
        cout<<part[i][j];
    cout<<endl;
    } */
 
    return dp[sum / 2][n];
}