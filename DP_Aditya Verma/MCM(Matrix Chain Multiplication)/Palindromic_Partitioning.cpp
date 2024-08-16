#include<bits/stdc++.h>
using namespace std;

//Recursion Only
// bool isPalindrome(string s,int start,int end){
//     while(start<=end){
//         if(s[start++]!=s[end--]){
//             return false;
//         }
//     }
//     return true;
// }
   
   
//    void solve(int index,vector<vector<string>>& ans, vector<string>& output,string s){
//        if(index>=s.length()){
//            ans.push_back(output);
//            return;
//        }
//        for(int i=index;i<s.length();i++){
//            if(isPalindrome(s,index,i)){
//                output.push_back(s.substr(index,i-index+1));
//                solve(i+1,ans,output,s);
//                output.pop_back();

//            }
//        }
//    }
   
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> ans;
//         vector<string> output;
//         solve(0,ans,output,s);
//         return ans;
//     }



    //DP

        int dp[500][500];
 
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return 0;
        }
        return 1;
    }

    int solve(string &s,int i,int j){
        if(i>= j){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(isPalindrome(s,i,j)) return dp[i][j]= 0;
        int ans = j-i+1;
        for(int k= i; k<=j-1; k++){
            if(dp[i][k] != -1)
            ans = min(ans, 1+dp[i][k] + solve(s,k+1,j));
            else if(dp[k+1][j]!= -1){
                 ans = min(ans, 1+dp[k+1][j] + solve(s,i,k));
            }
            else if(dp[i][k] != -1 && dp[k+1][j] != -1)
            {
                ans = min(ans, 1+dp[k+1][j] + dp[i][k]);
            }
            else{
                ans = min(ans, 1+solve(s,k+1,j) + solve(s,i,k));
            }
        }
        return dp[i][j] = ans;
    }

    int palindromicPartition(string &s)
    {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        return solve(s,0,n-1);
         
    }

