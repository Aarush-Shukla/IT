#include <bits/stdc++.h> 
using namespace std;
string removeDuplicates(string s) {
    string ans = "";                // String to store the Final result
    for(int i=0;i<s.length();i++) {
         if(ans.empty()) {          // if 'ans' is empty then just add the current char of string 's'
            ans+=s[i];
        } else {                    // else compare the current char of string 's' with last char of 'ans'               

            // if they are equal then take out last element from 'ans' else put that current element in the ans
            if(s[i] == ans[ans.length()-1]) {
                ans.pop_back();
            } else {
                ans+=s[i];
            }
        }
    }
    return ans;                     // return the result
}