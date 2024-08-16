#include <bits/stdc++.h> 
using namespace std;

   
//    T.C-(O(NLogN))  S.C-(O(N)) 
   
   //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        //minHeap used as wee want to find the sum of first two smallest elements
       priority_queue<long long,vector<long long>,greater<long long>> pq;
       
       for(int i=0;i<n;i++){
           pq.push(arr[i]);
       }
       
       long long cost=0;
       while(pq.size()>1){
           long long a =pq.top();
           pq.pop();
           long long b=pq.top();
           pq.pop();
           long long sum=a+b;
           cost += sum;
           
           pq.push(sum);
       }
       return cost;
    }