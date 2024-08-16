#include <bits/stdc++.h> 
using namespace std;


//T.C-(O(N)),S.C-(O(N))
int main(){
    string str="Babbar";
    stack<char> s;
    for(int i=0;i<str.length();i++){
       char ch= str[i];
       s.push(ch);
    }
    string ans="";
    while(!s.empty()){
        char ch=s.top();
        ans.push_back(ch);
        s.pop();
    }
  cout<<"ans is "<<ans<<endl;
}