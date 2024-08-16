#include <bits/stdc++.h> 
using namespace std;

bool isValidParenthesis(string expression)
{
 stack<char> s;
 for (int i = 0; i < expression.length(); i++) {
   char ch = expression[i];

   // if opening bracket,stackpush
   // if closing bracket, stacktop check and pop

   if(ch=='(' || ch=='{' || ch=='[' ){
     s.push(ch);
   }else{
       //for closing bracket
       if(!s.empty()){
           char top=s.top();
           if(ch==')' && top=='('||
              ch=='}' && top=='{'||
              ch==']' && top=='['){
                  s.pop();
              }else{
                  return false;
              }
       }else{
           //empty stack hai aur usme },],) dekh rahe
           return false;
       }
   }
 }
 if(s.empty())
    return true;
 else
 return false;
}