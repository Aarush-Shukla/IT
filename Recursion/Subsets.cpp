#include <bits/stdc++.h> 
using namespace std;
    
   //method 1
    void solve( vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }
        //exclude
        solve(nums,output,index+1,ans);
        //include
    
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        vector<int> output;
        solve(nums,output,index,ans);
        return ans;
        
    }
    
    
    //Method 2(Bit Manipulation)

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0;i<(1<<n);i++)
        {
            vector<int> op;
            for(int j = 0;j<n;j++)
            {
                if((1<<j)&i)            //for checking set at that place
                {
                    op.push_back(nums[j]);
                }
            }
            ans.push_back(op);
        }
        return ans;
    }
