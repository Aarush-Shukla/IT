#include <bits/stdc++.h> 
using namespace std;
void selectionSort(int *arr, int i,int n)
{   
    //base case
     if(n==0 || n==1){
         return;
    }
   
    for(i=0;i<n-1;i++){
        int MinIndex=i;
        for(int j=i+1;j<n;j++){
            if( arr[j]< arr[MinIndex]){
                MinIndex=j;
            }
 
        }
        swap(arr[MinIndex],arr[i]);
    }

    selectionSort(arr,i+1,n-1);
}
int main() {

    int arr[5] = {2,5,1,6,9};
    
    selectionSort(arr,0,5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}