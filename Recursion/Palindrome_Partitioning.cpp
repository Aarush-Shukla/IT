#include <bits/stdc++.h> 
using namespace std;

bool isPalindrome(string s,int start,int end){
    while(start<=end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}
   
   
   void solve(int index,vector<vector<string>>& ans, vector<string>& output,string s){
       if(index>=s.length()){
           ans.push_back(output);
           return;
       }
       for(int i=index;i<s.length();i++){
           if(isPalindrome(s,index,i)){
               output.push_back(s.substr(index,i-index+1));
               solve(i+1,ans,output,s);
               output.pop_back();

           }
       }
   }
   
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(0,ans,output,s);
        return ans;
    }