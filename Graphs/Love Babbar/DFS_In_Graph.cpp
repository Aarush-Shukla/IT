#include <bits/stdc++.h> 
using namespace std;

// DFS is done recursively

// T.C-O(N),S.C-O(N)


void AdjList(vector<vector<int>> &edges,unordered_map<int,list<int>> &adjList){

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}


void dfs(int &node,vector<int> &component,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited){

    //component mai push kardo pehla node aur usko true mark kar do
    component.push_back(node);
    visited[node]=true;

    //phir jo node ko push kiye component mai ussi ke corresponding list ko jaake uske har ek element ke liye wapas se dfs laga diye 
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i,component,adjList,visited);
        }
    }
}




vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
   unordered_map<int,bool> visited;
   unordered_map<int,list<int>> adjList;


    //adj list prepare kar liye
    AdjList(edges,adjList);

    //final ans store karne ke liye
   vector<vector<int>> ans;

    //har node pe jaake dekh rahe
   for(int i=0;i<V;i++){
       if(!visited[i]){
           vector<int> component;
           dfs(i,component,adjList,visited);
           ans.push_back(component);
       }
   }
   return ans;
}