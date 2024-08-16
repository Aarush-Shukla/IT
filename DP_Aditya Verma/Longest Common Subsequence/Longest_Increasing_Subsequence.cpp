#include<bits/stdc++.h>
using namespace std;

// Try to think it this way:

// For an index i: always try to find LIS of the subarray from 0 to i - 1 and append the current a[i] to the end of it, but that takes O(n^2) so to do everything parallely we use lower_bounds. in programming terms, you find the lower_bound (lower_bound because we need strictly increasing subsequence) of current element and replace it with a[i],if it is not found that means the current element is the largest element thus far so you append to your LIS array.

// Time Complexity: O(N * log(N));

// Space Complexity: O(N) --- actually θ(LIS);


int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> ans;
       for(int i=0;i<n;i++){
           auto it = lower_bound(ans.begin(),ans.end(),a[i]);
           if(it == ans.end()) ans.push_back(a[i]);
           else ans[it - ans.begin()] = a[i];
       }
       return ans.size();
    }