#include <bits/stdc++.h> 
using namespace std;

bool printS(int arr[],vector<int>& ds,int s, int sum,int index,int n){

    if(index==n){
        //condition satisfied
        if(s==sum){
            for(auto it:ds){
                cout<<it<<" ";
                }
            cout<<endl;
            return true;
        }
        //condition not satisfied
        else return false;
    }
    //include
    ds.push_back(arr[index]);
    s+=arr[index];
    if(printS(arr,ds,s,sum,index+1,n)==true){
       return true;
    }
    s-=arr[index];
    ds.pop_back();
    //exclude
    if(printS(arr,ds,s,sum,index+1,n)==true){
        return true;
    }
    return false;
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