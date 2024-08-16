#include <bits/stdc++.h> 
using namespace std;

void insertAtBottom(stack<int> &s,int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int num=s.top();
    s.pop();
    //recursive call
    insertAtBottom(s,element);
    //element ko jo nikala hai vo wapis daalo
    s.push(num);
}

void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    //element ko side mai nikal ke rakh diya
    int num=stack.top();
    stack.pop();
    //recursive call
    reverseStack(stack);
    //insert a element at bottom wla function se jo upar element nikala hai usko stack mai daal do
    insertAtBottom(stack,num);
}