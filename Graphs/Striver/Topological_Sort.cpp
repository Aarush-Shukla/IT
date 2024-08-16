#include <bits/stdc++.h>
using namespace std;


// Using DFS

	void dfs(int node, int vis[], stack<int> &st,
	         vector<int> adj[]) {
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) dfs(it, vis, st, adj);
		}
		st.push(node);
    }
	
    
//Function to return list containing vertices in Topological order.

	vector<int> topoSort(int V, vector<int> adj[])
	{
		int vis[V] = {0};
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, st, adj);
			}
		}

		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}






//Using BFS / KAHN's Algorithm

// vector<int> topoSort(int V, vector<int> adj[]) {

// 		int indegree[V] = {0};
// 		for (int i = 0; i < V; i++) {
// 			for (auto it : adj[i]) {
// 				indegree[it]++;
// 			}
// 		}

// 		queue<int> q;
// 		for (int i = 0; i < V; i++) {
// 			if (indegree[i] == 0) {
// 				q.push(i);
// 			}
// 		}
// 		vector<int> topo;
// 		while (!q.empty()) {
// 			int node = q.front();
// 			q.pop();
// 			topo.push_back(node);
// 			// node is in your topo sort
// 			// so please remove it from the indegree

// 			for (auto it : adj[node]) {
// 				indegree[it]--;
// 				if (indegree[it] == 0) q.push(it);
// 			}
// 		}

// 		return topo;
// 	}