#include <bits/stdc++.h> 
using namespace std;

 //i=0 to n/2-1   T.C(O(LogN))
    void Maxheapify(vector<int> &arr,int n,int i){
        int largest=i;
        int left=2*i + 1;
        int right=2*i + 2;
        
        if(left<n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<n && arr[largest]<arr[right]){
            largest=right;
        }


        //update karna hai as tabhi hoga jab initial largest = i se koi change aayega
        if(largest!=i){
             swap(arr[i],arr[largest]);
             Maxheapify(arr,n,largest);
            }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        //step1- create a new array and push all the elements into it
        // T.C-(O(M+N))  S.C-(O(M+N))
        vector<int>ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        
        //step2- MaxHeapify it
        int size=ans.size();
        for(int i=size/2-1;i>=0;i--){
            Maxheapify(ans,size,i);
        }
        
        return ans;
        
    }