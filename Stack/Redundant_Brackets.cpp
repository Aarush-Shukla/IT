#include <bits/stdc++.h> 
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];

        if(ch=='(' || ch=='*' || ch=='+' || ch=='-' || ch=='/'){
            st.push(ch);
        }else{
            // ch ya toh')' hai ya toh operator hai
            if(ch==')'){
                bool isReduntant=true;
                 while(st.top()!='('){
                 char top=st.top();
                 if(top=='*' || top=='+' || top=='-' || top=='/'){
                    isReduntant=false;
                 }
                 //operator ko hatane ke liye
                 st.pop();
                }
                if (isReduntant==true)
                return true;
                //brackets ko hatane ke liye
                st.pop();
            }
        }
    }
    return false;
}