#include <bits/stdc++.h> 
using namespace std;

//T.C-O(N),S.C-O(N)
 queue<int> rev(queue<int> q)
    {
        stack<int> s;
        while(!q.empty()){
            int element=q.front();
            q.pop();
            s.push(element);
        }
        while(!s.empty()){
            int element=s.top();
            s.pop();
            q.push(element);
        }
        return q;
    }