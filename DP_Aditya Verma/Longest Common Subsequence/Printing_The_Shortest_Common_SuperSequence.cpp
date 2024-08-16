#include<bits/stdc++.h>
using namespace std;

// Below is the detailed explanation for printing of supersequence.  Here we first do lcs and then like @Aditya showed in printing of LCS you can check for following:
// 1. if character exists in both add to string.
// 2. if not check dp[i][j-1] >dp[i-1][j] which means the str which represents column its jth is not common so push that but dont push row as chances are it can still exist.
// 3. Do opposite in else.
// 4. once out of while loop check if i or j is greater and insert them into string.

// Below is the code for that:

string lcs(string str1, string str2, int m , int n) {
       
       //lcs creation
        int dp[m+1][n+1];
        
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                if(i==0 || j==0)
                    dp[i][j] = 0;
        
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(str1[i-1]==str2[j-1]) {
                    dp[i][j] = 1+ dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        //printing the supersequence
        int i=m,j=n;
        string s;
        while(i>0 && j>0) {
            if(str1[i-1] == str2[j-1])
            {
                s.push_back(str1[i-1]);
                i--;
                j--;
            } else {
                if(dp[i][j-1] > dp[i-1][j]) {
                    s.push_back(str2[j-1]);
                    j--;
                } else {
                    s.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        
        while(i > 0) {
            s.push_back(str1[i-1]);
            i--;
        }
        
        while(j > 0) {
            s.push_back(str2[j-1]);
            j--;
        } 
        
        reverse(s.begin(), s.end());
        return s;
    }