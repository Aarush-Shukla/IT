#include <bits/stdc++.h> 
using namespace std;

// ************************************
// Kth smallest element-> use MaxHeap *
// Kth largest element-> use MinHeap  *
// ************************************



//Approach 1-  T.C- O(N-K(log K)) 

// arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        
        //step1- push first K elements in pq
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        //step2- compare with pq.top()
        for(int i=k;i<=r;i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        int ans=pq.top();
        return ans;
    }





// Approach 2-T.C-(O(N log (k)))
//     int kthSmallest(int arr[], int l, int r, int k) {
//         priority_queue<int> q;
//         for (int i = l ; i < r+1 ; i++){
//             q.push(arr[i]);
//         }
//         while (q.size() > k){
//             q.pop();
//         }
//         return q.top();
//     }