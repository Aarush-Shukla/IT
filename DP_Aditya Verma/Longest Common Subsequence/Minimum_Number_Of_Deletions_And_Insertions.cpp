#include<bits/stdc++.h>
using namespace std;

int lcs(int n, int m, string s1, string s2){
    n=s1.length();
    m=s2.length();

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

	int minOperations(string str1, string str2) 
	{ 
	    int n=str1.length();
	    int m=str2.length();
	    
	    int deletion= n-lcs(n,m,str1,str2);
	    int insertion= m-lcs(n,m,str1,str2);
	    
	    return deletion+insertion;
	} 