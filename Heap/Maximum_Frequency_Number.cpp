#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> m;
    
    int maxAns=0;
    int maxFreq=0;

    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
        maxFreq=max(maxFreq,m[arr[i]]);
    }

    for(int i=0;i<arr.size();i++){
        if(maxFreq==m[arr[i]]){
            maxAns=arr[i];
            break;
        }
    }
    return maxAns;
}