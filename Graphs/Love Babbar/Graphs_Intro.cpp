#include <bits/stdc++.h>
using namespace std;
template <typename T>

class graph{
public:
 
    unordered_map<T,list<T>> adj_list ;

    // For AdjList:- n->node , m-> edges
    // Add Edge T.C: O(m) and S.C: O(n+m)
    // Print Edge T.C: O(n*m) and S.C: O(1)

    
    void addEdge(T u,T v,bool direction){
        
        adj_list[u].push_back(v);
        
        //direction=0 -> undirected
        //direction=0 -> directed
        if(direction ==0){
            adj_list[v].push_back(u);
        }
    }


    void print_Adj_List(){
        for(auto i:adj_list){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
                    }      
            cout<<endl;
        }
    }
};


int main(){

    int n;
    cout<<"Enter the number of Nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the number of Edges"<<endl;
    cin>>m;


    graph<int> g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    g.print_Adj_List();


}