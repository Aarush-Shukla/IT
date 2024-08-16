#include <bits/stdc++.h> 
using namespace std;

   int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int area=0;
       
    
        while(i<j){
        int b=j-i;
        int l=min(height[i],height[j]);
        area=max(area,l*b);
        if(height[i]<height[j]){
            i++;
            } else{
                j--;
                }
            }
        return area;
    }