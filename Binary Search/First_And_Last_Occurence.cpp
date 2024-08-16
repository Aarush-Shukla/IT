#include <bits/stdc++.h> 
using namespace std; 

int FirstOcc(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=(start+(end-start)/2); //(start+end)/2 == (start + (end-start)/2) to avoid edge cases(if start=2^31 -1 and end= 2^31 -1)
    int ans=-1;
    while(start<=end){
        if(key==arr[mid]){
            ans = mid;
            end=mid-1;
        }
        if(key>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
        mid=(start+(end-start)/2);
    }
    return ans;
}

int LastOcc(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=(start+(end-start)/2); //(start+end)/2 == (start + (end-start)/2) to avoid edge cases(if start=2^31 -1 and end= 2^31 -1)
    int ans=-1;
    while(start<=end){
        if(key==arr[mid]){
            ans = mid;
            start=mid+1;
        }
        else if(key>arr[mid]){
            start=mid+1;
        }else if(key<arr[mid]) {
            end=mid-1;
        }
        mid=(start+(end-start)/2);
    }
    return ans;
}
int main(){
    int even[8]={1,2,3,4,5,5,5,9};
     int odd[5]={2,4,6,8,10};
     int Firstindex=FirstOcc(even,8,5);
     int Lastindex=LastOcc(even,8,5);
     cout<< Firstindex<<endl;
     cout<< Lastindex<<endl;


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k);{ 
    pair<int,int> p;
    p.first=FirstOcc(arr,n,k);
    p.second=LastOcc(arr,n,k);

    return p;
     
}

}