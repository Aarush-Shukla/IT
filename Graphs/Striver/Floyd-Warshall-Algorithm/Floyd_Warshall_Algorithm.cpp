#include <bits/stdc++.h>
using namespace std;


// Even if all the weights are positive, why Dijkstra might not be preferred over Floyd Warshall is because for Dijkstra, time complexity is
// V * E * log(V)
// For dense graphs,
// E ~ V^2 since E = V (V-1)/2 for a fully connected graph
// Making the time complexity
// V^3 * log(V)



    void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	            if(i==j){
	                matrix[i][j]=0;
	            }
	        }
	    }
	    
	    for(int k=0;k<n;k++){
	     for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	           matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	        }
	    }
	}
	
	
	for(int i=0;i<n;i++){
	    if(matrix[i][i]<0){
	        cout<<"Negative Cycle";
	    }
	}
	    
	     
	     for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]= -1;
	            }
	           
	        }
	    }
	    
	}