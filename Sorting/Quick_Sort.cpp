#include <bits/stdc++.h> 
using namespace std;

int partition(vector<int>& arr,int s,int e){
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
             cnt++;
        }
    }
    int pivotIndex=s+cnt;
    swap(arr[pivotIndex],arr[s]);
   
   int i=s;
   int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
         while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;

}


void Solve(vector<int>& arr,int s,int e){
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);
    Solve(arr,s,p-1);
    Solve(arr,p+1,e);
}

vector<int> quickSort(vector<int> arr)
{
    Solve(arr,0,arr.size()-1);
    return arr;
}