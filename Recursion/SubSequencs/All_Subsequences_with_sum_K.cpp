#include <bits/stdc++.h> 
using namespace std;

void printS(int arr[],vector<int>& ds,int s, int sum,int index,int n){

    if(index==n){
        if(s==sum){
            for(auto it:ds){
                cout<<it<<" ";
                }
            cout<<endl;
        }
        return;
    }
    //include
    ds.push_back(arr[index]);
    s+=arr[index];
    printS(arr,ds,s,sum,index+1,n);
    s-=arr[index];
    ds.pop_back();
    //exclude
    printS(arr,ds,s,sum,index+1,n);
}

    int main(){
        int arr[]={1,2,1};
        int n=3;
        int sum=2;
        vector<int> ds;
	    int index=0;
	    int s=0;
	    printS(arr,ds,s,sum,index,n);
	    return 0;
        }