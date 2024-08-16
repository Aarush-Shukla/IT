 #include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                      
                      
                      int i=0;
                      int j=0;
                      vector<long long> vec;
                      list<long long> lis;
                      while(j<N){
                          if(A[j]<0){
                              lis.push_back(A[j]);//j ke liye calculation cover karna
                          }
                          if(j-i+1<K){   //if( < K) then j++
                              j++; // moving j till window K is formed
                          }
                          
                          else if(j-i+1==K){      //if( == K)
                              if(lis.size()==0){      //calculation to provide ans
                                  vec.push_back(0);
                              }else{
                                  vec.push_back(lis.front());// basic calculation required for the given condition
                                  if(A[i]==lis.front()){
                                      lis.pop_front();  //i ke liye calculation cover karna, j ke liye already cover ho chuki upar
                                  }
                              }
                              i++;  //sliding the window
                              j++;
                          }
                          
                      }
                      
             return vec;                                    
 }