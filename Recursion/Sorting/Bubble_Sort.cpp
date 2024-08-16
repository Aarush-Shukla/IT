#include <bits/stdc++.h> 
using namespace std;
void bubbleSort(int *arr, int n)
{   
    // for(int i=1;i<n;i++){
    //     bool swapped=false;
    //     for(int j=0;j<n-i;j++){
    //         if(arr[j]>arr[j+1]){
    //             swap(arr[j],arr[j+1]);
    //             swapped=true;
    //         }
    //     }
    //     if(swapped==false){
    //         //already sorted array
    //         break;
    //     }
    // }


    //Base Case 
    if(n==0 || n==1){
         return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,n-1);
}

int main() {

    int arr[5] = {2,5,1,6,9};
    
    bubbleSort(arr,5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}


