#include<bits/stdc++.h>
using namespace std;
     
     //using map
     
     int longestUniqueSubsttr(string S){
        int i=0;
        int j=0;
        int maxLen=0;
        int n=S.length();
        unordered_map<char,int> mp;
        while(j<n){
            mp[S[j]]++;
            if(mp.size()==j-i+1){
                maxLen=max(maxLen,j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[S[i]]--;
                    if(mp[S[i]]==0){
                        mp.erase(S[i]);
                    }
                    i++;
                }
            j++;    
            }
        }
        return maxLen;
    }

//using array

    int longestUniqueSubsttr(string s){
        int i=0;
        int j=0;
        int ans=INT_MIN;
        
        int m[26]={0};
        
        while(j<s.size())
        {
            m[s[j]-'a']++;
            if(m[s[j]-'a']==1)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            
            else if(m[s[j]-'a']>1)
            {
                while(m[s[j]-'a']>1)
                {
                    m[s[i]-'a']--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }