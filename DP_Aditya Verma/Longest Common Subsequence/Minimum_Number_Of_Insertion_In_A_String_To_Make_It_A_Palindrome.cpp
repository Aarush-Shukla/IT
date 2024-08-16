#include<bits/stdc++.h>
using namespace std;

// Simply think of this as, 
// => Total elements - (Those already forming a palindromic sub-sequence) 
// //This palindromic sub-sequence has to be largest in order to minimise the insertions.
// Also, largest palindromic subsequence for a given str => LCS(str, reverse of str);

// So, final answer => n - (LCS(str, reverse of str));
//basically no.of insertion= no.of deletion of lps(longest palindromic subsequence)



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

    int findMinInsertions(string S){
     string B=string(S.rbegin(),S.rend());//reverse the string
       
       int p=S.length();
       int q=B.length();
       return p-lcs(p,q,S,B);
    }



// I did it with SCS. if s = "abcd" then the palindrome is "dcbabcd"
// So if we get SCS of [reverse(s),s], we get dcbabcd. I just substract SCS with len(s) and it worked
// len(SCS) - len(LCS) will also give no. of insertions. thus finally len(a)+len(b)-2*len(lcs) where b = a.reverse()