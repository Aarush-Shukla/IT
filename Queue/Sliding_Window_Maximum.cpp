#include <bits/stdc++.h> 
using namespace std;

 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n=nums.size();
        vector<int> ans;

        //First K Window
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]){// Jab array ka element bada hai queue se toh queue ke element ko pop karke uski jagah vo element push kardo
                dq.pop_back();
                
            }
            dq.push_back(i);
        }
ans.push_back(nums[dq.front()]);

//for remaining iterations
for(int i=k;i<n;i++){

    //next window
    //removal of first element;
    while(!dq.empty()&& i-dq.front()>=k){
        dq.pop_front();
    }

    //addition

    while(!dq.empty() && nums[i]>=nums[dq.back()]){// Jab array ka element bada hai queue se toh queue ke element ko pop karke uski jagah vo element push kardo
                dq.pop_back();
                
            }
    dq.push_back(i);

    ans.push_back(nums[dq.front()]);       

    }
       return ans;
}