#include<bits/stdc++.h>
using namespace std;
 
   int longestKSubstr(string s, int k) {
    int n=s.length();
    int i=0;
    int j=0;
    int maxLen=0;
    unordered_map<char,int> mp;//charachter,length
    while(j<n){
        mp[s[j]]++;
        if(mp.size()<k){
            j++;
        }
        else if(mp.size()==k){
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        else if(mp.size()>k){ 
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
                
            }
        
            j++;
        }
        
    }
    if(maxLen==0)return -1;
    return maxLen;
    
    }