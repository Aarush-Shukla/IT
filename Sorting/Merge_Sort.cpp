#include <bits/stdc++.h> 
using namespace std;


void Merge(int *arr,int s,int e){
int start=s;
int end=e;
int mid=s+ (e-s)/2;
int len1=mid-s+1;
int len2=e-mid;
int *first=new int[len1];
int *second=new int[len2];
int mainarrayindex=s;

//copy the elements into two subarrays
for(int i=0;i<len1;i++){
first[i]=arr[mainarrayindex++];

}
mainarrayindex=mid+1;
for(int i=0;i<len2;i++){
second[i]=arr[mainarrayindex++];

}
//Merge 2 sorted arrays
int index1=0;
int index2=0;
mainarrayindex=s;
while(index1<len1 && index2<len2){
    if(first[index1]<second[index2]){
        arr[mainarrayindex++]=first[index1++];
    }else{
        arr[mainarrayindex++]=second[index2++];
    }
}
while(index1<len1){
     arr[mainarrayindex++]=first[index1++];
}
while(index2<len2){
     arr[mainarrayindex++]=second[index2++];
}
delete []first;
delete []second;


}
void solve(int *arr,int s,int e){
if(s>=e){
    return;
}
int mid=s+(e-s)/2;

solve(arr,s,mid);
solve(arr,mid+1,e);
Merge(arr,s,e);
}



int main() {

    int arr[5] = {2,5,1,6,9};
    
    solve(arr,0,5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}