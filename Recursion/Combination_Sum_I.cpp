 #include <bits/stdc++.h> 
using namespace std;

 void findCombination(int index,vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>& ds){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
             return;
        }
        //pick up element
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            findCombination(index,candidates,target-candidates[index],ans,ds);
            ds.pop_back();
            }
        //exclude
         findCombination(index+1,candidates,target,ans,ds);

         //tc=(2^t)*k;
         //sc=k*x;

       
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
         vector<int> ds;
         int index=0;
         findCombination(index,candidates,target,ans,ds);
         return ans;
    }