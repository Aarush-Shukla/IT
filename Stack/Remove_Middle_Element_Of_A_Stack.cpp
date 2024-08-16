#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>&inputStack, int size,int count){
   // base case
   if(count==size/2){
      inputStack.pop();
      return;
   }

   //jo top se leke middle tak jitne bhi elements hai unko alag se nikal ke rakh lo
   int num=inputStack.top();
   inputStack.pop();

   //Recursive Call
   solve(inputStack,size,count+1);

  //jis element ko nikala tha usko wapis daal do
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   int count=0;
   solve(inputStack,N,count);
   }