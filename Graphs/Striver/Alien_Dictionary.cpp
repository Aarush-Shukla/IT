#include <bits/stdc++.h>
using namespace std;
    
    //BFS using toposort

    vector<int> topoSort(int V, vector<int> adj[]){
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}



	string findOrder(string dict[], int N, int K) {
		vector<int>adj[K];
		for (int i = 0; i < N - 1; i++) {
			string s1 = dict[i];
			string s2 = dict[i + 1];
			int len = min(s1.size(), s2.size());
			for (int ptr = 0; ptr < len; ptr++) {
				if (s1[ptr] != s2[ptr]) {
					adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
					break;
				}
			}
		}

		vector<int> topo = topoSort(K, adj);
		string ans = "";
		for (auto it : topo) {
			ans = ans + char(it + 'a');
		}
		return ans;
	}




    //DFS  

    class Solution
{
private:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &s)
    {
        vis[node] = 1;

        for (int v : adj[node])
        {
            if (vis[v] == 0)
            {
                if (dfs(v, adj, vis, s) == false)
                    return false;
            }
            else if (vis[v] == 1)
                return false;
        }

        s.push_back(node);
        vis[node] = 2;
        return true;
    }

    vector<int> dictionary(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);

        vector<int> s;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, adj, vis, s);
            }
        }

        if (s.size() != V)
            return {};

        reverse(s.begin(), s.end());

        return s;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];

        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            int len = min(s1.size(), s2.size());

            for (int idx = 0; idx < len; idx++)
            {
                if (s1[idx] != s2[idx])
                {
                    adj[s1[idx] - 'a'].push_back(s2[idx] - 'a');
                    break;
                }
            }
        }

        vector<int> ans = dictionary(K, adj);
        string str_ans = "";

        for (int v : ans)
        {
            str_ans = str_ans + char(v + 'a');
        }

        return str_ans;
    }
};