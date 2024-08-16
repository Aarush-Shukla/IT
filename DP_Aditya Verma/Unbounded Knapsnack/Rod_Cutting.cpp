#include <bits/stdc++.h>
using namespace std;

//Approach 1. RC + Memoization (Top Down DP)

    int t[1002][1002];
    int helper(int price[], int length[], int n, int i){
        if(n == 0 || i == 0) return 0; //Base case is there is no rod or there is not price then profit will be 0
        
        if(t[n][i] != -1) return t[n][i]; //Checking our cache for sub-problem
        
        if(length[n-1] <= i){
            //We can cut in current size or we cant cut in current size, Multiple sizes are allowed
            return t[n][i] = max(price[n-1]+helper(price, length, n, i-length[n-1]), helper(price, length, n-1, i));
        }
        
        //we cant cut in current size coz we dont hv enough size of rod
        else return t[n][i] = helper(price, length, n-1, i);
    }
  
    int cutRod(int price[], int n) {
        memset(t, -1, sizeof(t));
        //Creating a length array for simplicity of our approach
        int length[n];
        for(int i=0;i<n;i++) length[i] = i+1;
        return helper(price, length, n, n);
    }




    //Approach 2. Tabulation (Bottom Up DP)

    int cutRod(vector<int> &price, int n) {
	int w=n;
	int length[n];
	for(int i=1;i<=n;i++)
	{
		length[i]=i;
	}
    vector<vector<int>> t(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (length[i] <= j) {
                t[i][j] = max(price[i-1] + t[i][j - length[i]], t[i - 1][j]);
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][w];
}