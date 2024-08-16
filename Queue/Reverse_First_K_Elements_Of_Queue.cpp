#include <bits/stdc++.h> 
using namespace std;

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
   stack<int> s;
   //first k elements
   for(int i=0;i<k;i++){
       int val=q.front();
       q.pop();
       s.push(val);
   }
   
   while(!s.empty()){
       int val=s.top();
       s.pop();
       q.push(val);
   }
   // for the rest n-k size
   int t=q.size()-k;
   
   while(t--){
       int val=q.front();
       q.pop();
       q.push(val);
   }
   return q;
}