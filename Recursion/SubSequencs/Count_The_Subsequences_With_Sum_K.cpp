#include <bits/stdc++.h> 
using namespace std;

int printS(int arr[],int s, int sum,int index,int n){

    if(index==n){
        //condition satisfied
        if(s==sum){
            return 1;
        }
        //condition not satisfied
        else return 0;
    }
    //include
    s+=arr[index];
    int l= printS(arr,s,sum,index+1,n);
    s-=arr[index];
    //exclude
    int r= printS(arr,s,sum,index+1,n);

    return l+r;
}

    int main(){
        int arr[]={1,2,1};
        int n=3;
        int sum=2;
        int index=0;
	    int s=0;
	    cout << printS(arr,s,sum,index,n);
	    return 0;
        }