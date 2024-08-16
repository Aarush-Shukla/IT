#include <bits/stdc++.h> 
using namespace std;

    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
           int move = 0;
           int A=from;
           int B=aux;
           int C=to;
        if (N==1){
            cout << "move disk " <<N<< " from rod "<<A<< " to rod "<<C<< "\n";
            return move+1;
        }
        
        move+=toh(N-1,A,B,C);
        cout << "move disk " <<N<< " from rod " <<A<< " to rod " <<C <<"\n";
        move+=toh(N-1,B,C,A);
        return move+1;
    
    }