#include <bits/stdc++.h> 
using namespace std;

int findMinimumCost(string str) {
  if(str.length()%2==1){
    return -1;
  }
  
  stack<char> s;
  for(int i=0;i<str.length();i++){
    char ch=str[i];
//saare valid vaalo ko nikalna hai
    if(ch=='{'){
      s.push(ch);
    } else {
      // } aaya hai
      if(!s.empty()&& s.top()=='{'){
        s.pop();
          }else{
        s.push(ch);
          }
      }
   }

    //saare invalid vaale bache stack mai
      int a=0; int b=0;
      while(!s.empty()){
        if(s.top()=='{'){
          a++;
      } else {
          b++;
          }
        s.pop();
      }
      int ans= (a+1)/2  +  (b+1)/2;
      return ans;
  }