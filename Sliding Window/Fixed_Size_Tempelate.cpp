#include<bits/stdc++.h>
using namespace std;

    vector<int> function(vector<int> arr, int n, int k) {
        int i=0;
        int j=0;
        vector<int>ans;
        deque<int> dq;
        while(j<n){
           
           //calculation
            
            if(j-i+1<k){ // make it reach till the size of sliding window
                j++;
            }
            
           else if(j-i+1==k){
                
               //ans <-  calculation to store it in final ans

                //slide the window
                //1) remove the calculations for i th window
                //2) increase the window with i++,j++;
                i++;
                j++;
            }
            
        }
        
        return ans;
        
    }