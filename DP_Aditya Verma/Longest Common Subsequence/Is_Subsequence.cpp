#include<bits/stdc++.h>
using namespace std;

//Method-1 (2 pointer)
    bool isSubsequence(string s, string t) {
         int j=0;
        for(int i=0;i<t.size();i++)
        {
                     if(s[j]==t[i])
                    {
                               j++;
                    }
                    if(j==s.size())
                    {
                               break;
                    }
        }
        if(j==s.size())
        {
                    return true;
        }
        else
        {
                    return false;
        }
    }






 // Method-2 (Dp)

  int lcs( string s1, string s2){
    int n=s1.length();
    int m=s2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1));
 
    //Base Case

for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){

        dp[i][0]=0;
        dp[0][j]=0;

    }
}

//Choice Diagram

for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){

        if(s1[i-1]==s2[j-1]){
        dp[i][j] = 1+dp[i-1][j-1];
        }
         else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
    
      return dp[n][m];

}
    
    
    bool isSubsequence(string s, string t) {
     int length=lcs(s,t);
     if(length==s.length()){
         return true;
     }else{
         return false;
     }
    }