#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>& s, int x){
   //base case
    if(s.empty()){
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    //recursive call
    solve(s,x);
    //wapas dalna hai element ko
    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}
