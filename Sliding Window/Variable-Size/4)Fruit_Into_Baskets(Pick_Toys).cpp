#include<bits/stdc++.h>
using namespace std;
 
     int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int maxi=1;
        unordered_map<int,int> mp;
        while (j<fruits.size())
        {
            mp[fruits[j]]++;
            while (mp.size()>2)
            {
                mp[fruits[i]]--;
                if (mp[fruits[i]]==0)
                    mp.erase(fruits[i]);
                i++;
            }
            if (mp.size()<=2)
                maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }