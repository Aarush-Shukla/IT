#include <bits/stdc++.h> 
using namespace std;


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
         deque<long long int> dq;
         vector<long long> ans;
         int negative = -1;
         
         //process first window
         for(int i=0; i<K; i++) {
             if(A[i] < 0) {
                 dq.push_back(i);//getting the index
             }
         }
         
         //push ans for FIRST window
         if(dq.size() > 0) {
             ans.push_back(A[dq.front()]); //dq.front() is a index
         }
         else
         {
             ans.push_back(0);
         }
         
         //now process for remaining windows
         for(int i = K; i<N; i++) {
             //first pop out of window element
             
             
             if(!dq.empty() && (i - dq.front())>=K ) {   // //dq.front() is a index
                 dq.pop_front();
             }
             
             //then push current element
             if(A[i] < 0)
                dq.push_back(i);
             
            // put in ans
            if(dq.size() > 0) {
                 ans.push_back(A[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
         }
         return ans;
 }


// approach 2

// typedef pair<int,int> pi;

// vector<long long> printFirstNegativeInteger(long long int A[],
//                                              long long int N, long long int K) {
                                                 
                                                 
//     queue<pi>q;
//     vector<long long>ans;
    
//     int i;
//     for( i=0; i<K-1; i++){
//         if(A[i]<0)q.push({A[i],i});
//     }
    
//     pi p;
    
//     int j =0;
//     while(i<N){
//         if(A[i]<0)q.push({A[i],i});
        
//         if(q.empty())ans.push_back(0);
        
//         else{
//             p = q.front();
//             ans.push_back(p.first);
            
//             if(p.second<=j)q.pop();
//         }
//         j++;
//         i++;
        
//     }
    
//     return ans;
//  }
