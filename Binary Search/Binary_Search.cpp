#include <bits/stdc++.h> 
using namespace std; 

int BinarySearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=(start+(end-start)/2); //(start+end)/2 == (start + (end-start)/2) to avoid edge cases(if start=2^31 -1 and end= 2^31 -1)
    while(start<=end){
        if(key==arr[mid]){
            return mid;
        }
        if(key>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
        mid=(start+(end-start)/2);
    }
    return -1;
}

int main(){
     int even[6]={1,3,5,7,9,13};
     int odd[5]={2,4,6,8,10};
     int evenindex=BinarySearch(even,6,13);
     cout<< evenindex<<endl;
}