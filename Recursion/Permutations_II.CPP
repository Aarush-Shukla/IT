#include <bits/stdc++.h> 
using namespace std;

 void solve(vector<int> &nums, int idx, vector<vector<int>> &res) {
        // Base Case
        int n = nums.size();
        if(idx == n) {
            res.push_back(nums);
            return;
        }
        // Recursive Step
        for(int i = idx; i < n; i++) {
            if(i != idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            solve(nums, idx + 1, res);
        }
        for(int i = n - 1; i > idx; i--)         // Dont need to do this if passing nums by value.
            swap(nums[i], nums[idx]);
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        solve(nums, 0, res);
        return res;
    }