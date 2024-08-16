 #include<bits/stdc++.h>
using namespace std;
 
 long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long sum=0;
        int i=0;
        int j=0;
        long maxi=INT_MIN;
        while(j<N){
            sum=sum+Arr[j];
            if(j-i+1<K){
                j++;
            }
            else if(j-i+1==K){
                maxi=max(sum,maxi);
                sum=sum-Arr[i];
                j++;
                i++;
            }
        }
        return maxi;
    }