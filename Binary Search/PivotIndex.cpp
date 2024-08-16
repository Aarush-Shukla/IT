// #include <bits/stdc++.h> 
// using namespace std; 

// int PivotIndex(int arr[],int size){
//     int ans;
//   for(int i=0;i<size;i++){
//     if(accumulate(arr,arr+i-1,0)==accumulate(arr+i+1,arr+size,0)){
//         ans=i;
//     }else {
//         return -1;
//     }
//     return ans;
// }

// }





// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//    int Pivot=PivotIndex(a,n);
//    cout<<Pivot<<endl;
// }

 int pivotIndex(int nums[]) {
   int sum=0;
   for (int i=0;i<nums.length;i++){
       sum+=nums[i];
   }
   int lsum=0;
   int rsum=sum;
   for(int i=0;i<nums.length;i++){
       rsum=rsum-nums[i];
      if(lsum==rsum){
          return i;
      }
      lsum+=nums[i];
   }
  return -1;
}
