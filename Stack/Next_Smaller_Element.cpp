#include <bits/stdc++.h> 
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
   stack<int> s;
   s.push(-1);
   vector<int>ans(n);

   for(int i=n-1;i>=0;i--){
       int curr=arr[i];
       //jab tak chota element(curr) nahi mil jaata usse jo abhi tak stack(s.top) mai hai, tab tak pop karna hai
       while(s.top()>=curr){
            s.pop();
       }
       //aur iss loop se agar nikal gaye iska matlab element mil gaya jo ki chota hai toh usko ans vector mai store kara lena hai 
       ans[i]=s.top();
       s.push(curr);
   }
   return ans;
}