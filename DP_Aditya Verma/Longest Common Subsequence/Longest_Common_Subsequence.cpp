 #include<bits/stdc++.h>
using namespace std;

//Method 1 -Recursion

int lcs(int n, int m, string s1, string s2){
    n=s1.length();
    m=s2.length();
    //Base Case
    if(n==0||m==0){
        return 0;
    }
    //Choice Diagram
     if(s1[n-1]==s2[m-1]){
        return 1+lcs(n-1,m-1,s1,s2);
    }else{
        return max(lcs(n-1,m,s1,s2),lcs(n,m-1,s1,s2));
    }
}


//Method 2- Memoization (Recursive call + Matrix)

int lcs(int n, int m, string s1, string s2){
    n=s1.length();
    m=s2.length();

    int dp[n+1][m+1];
    memset (dp,-1,sizeof(dp));

    //Base Case
    if(n==0||m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    //Choice Diagram
     if(s1[n-1]==s2[m-1]){
        dp[n][m] = 1+lcs(n-1,m-1,s1,s2);
    }else{
        dp[n][m] = max(lcs(n-1,m,s1,s2),lcs(n,m-1,s1,s2));
    }

    return dp[n][m];

}


//Method 3- Tabulation

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