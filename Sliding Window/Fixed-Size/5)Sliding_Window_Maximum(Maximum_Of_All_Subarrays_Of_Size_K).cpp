#include<bits/stdc++.h>
using namespace std;

    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        int i=0;
        int j=0;
        vector<int>ans;
        deque<int> dq;
        while(j<n){
            while(dq.size()>0 && dq.back()<arr[j] ){
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            
            if(j-i+1<k){
                j++;
            }
            
           else if(j-i+1==k){
                
                ans.push_back(dq.front());
                
                if(arr[i]==dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
            }
            
        }
        
        return ans;
        
    }