#include <bits/stdc++.h> 
using namespace std;

  vector<int> prevSmallerElement(int* heights,int n){
       stack<int> st;
       st.push(-1);
       vector<int> ans(n);
       for(int i=0;i<n;i++){
           int curr=heights[i];
           while((st.top()!=-1) && (heights[st.top()]>=curr)){
               st.pop();
           }
           ans[i]=st.top();
           st.push(i);
       }
       return ans;
   }


   vector<int> nextSmallerElement(int* heights,int n){
       stack<int> st;
       st.push(-1);
       vector<int> ans(n);
       for(int i=n-1;i>=0;i--){
           int curr=heights[i];
           while((st.top()!=-1) && (heights[st.top()]>=curr)){
               st.pop();
           }
           ans[i]=st.top();
           st.push(i);
       }
       return ans;
   }
   
    int largestRectangleArea(int* heights,int n) {
       
        vector<int> next(n);
        next=nextSmallerElement(heights,n);
        vector<int> prev(n);
        prev=prevSmallerElement(heights,n);
        
        int area=INT_MIN;

        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newArea=l*b;
            area=max(area,newArea);
        }
        return area;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
       //update first row
       int area=largestRectangleArea(M[0],m);
       //for next rows
       for(int i=1;i<n;i++){
           for(int j=0;j<m;j++){
               //row update-by adding previous row
               if(M[i][j]!=0){
                   M[i][j]=M[i][j]+M[i-1][j];
               }else{
                   M[i][j]=0;
               }
            }
            //entire row is updated now
            int newArea=largestRectangleArea(M[i],m);
            area=max(area,newArea);
       }
       return area;
    }