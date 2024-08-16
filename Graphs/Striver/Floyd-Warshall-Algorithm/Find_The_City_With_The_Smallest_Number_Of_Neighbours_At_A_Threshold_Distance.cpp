#include <bits/stdc++.h>
using namespace std;

//using Floyd Bellman


	int findCity(int n, int m, vector<vector<int>>& edges,
	             int distanceThreshold) {
		vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;

	}





// using dijkstra


 vector<int> dijkstra(int s,vector<pair<int,int>>adj[],int distanceThreshold,int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dist(n,INT_MAX);
        dist[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int wt=it.first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int d=it.second;
                if(wt+d<dist[adjNode]){
                    dist[adjNode]=wt+d;
                    pq.push({wt+d,adjNode});
                }
            }
        }
        return dist;
    }
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
           vector<pair<int,int>>adj[n];
           for(auto it:edges){
               int u=it[0];
               int v=it[1];
               int wt=it[2];
               adj[u].push_back({v,wt});
               adj[v].push_back({u,wt});
           }
           int mincity=-1,mincnt=1e9;
           for(int i=0;i<n;i++){
               vector<int>ans=dijkstra(i,adj,distanceThreshold,n);
               int cnt=0;
               for(auto it:ans){
                   if(it<=distanceThreshold){
                       cnt++;
                   }
               }
               if(cnt<=mincnt){
                   mincnt=cnt;
                   mincity=i;
               }
           }
        return mincity;
    }

   