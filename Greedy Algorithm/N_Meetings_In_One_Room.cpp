#include<bits/stdc++.h>
using namespace std;


    static bool cmp(pair<int,int>a,pair<int,int>b){
        return b.second>a.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int,int>> vec;
       for(int i=0;i<n;i++){
           pair<int,int> p=make_pair(start[i],end[i]);
           vec.push_back(p);
       }
       
       sort(vec.begin(),vec.end(),cmp);
       
       int count=1;
       int ansEnd=vec[0].second;
       
       for(int i=1;i<n;i++){
           if(vec[i].first>ansEnd){
               count++;
               ansEnd=vec[i].second;
           }
       }
       
       return count;
    }