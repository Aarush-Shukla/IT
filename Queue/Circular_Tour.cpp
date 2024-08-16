#include <bits/stdc++.h> 
using namespace std;

//The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};
  
  //T.C-(0(N)),S.C-(O(1))
   
   //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int kami=0;
       int balance=0;
       int start=0;
       for(int i=0;i<n;i++){
           balance=balance+p[i].petrol-p[i].distance;
           if(balance<0){
               kami=kami+balance;
               start=i+1;
               balance=0;
           }
       }
       if(balance+kami>=0){
           return start;
       }else{
           return -1;
       }
    }