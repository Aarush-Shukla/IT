int PivotIndex(vector<int>& arr,int n){
    int start=0;
    int end=n-1;
    int mid= start + (end-start)/2;
    while(start<end){
        if(arr[mid]>=arr[0]){
            start=mid+1;
        }else{
            end=mid;
        }
        mid= start + (end-start)/2;
    }
    return start;
}

int BinarySearch(vector<int>& arr,int s,int e,int k){
    
    int start=s;
    int end=e;
    int mid= start + (end-start)/2;
    while(start<=end){ 
        if(arr[mid]==k){
            return mid;
        }
        if(k>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
        mid= start + (end-start)/2;
    }
    return -1;
}



int search(vector<int>& arr, int n, int k)
{
   int Pivot= PivotIndex(arr, n);      
    
   if (k>=arr[Pivot] && k<=arr[n-1]){
    //BS on Second Line
    return BinarySearch(arr,Pivot,n-1,k);
   }else {
       //BS on First Line
       return BinarySearch(arr,0,Pivot-1,k);
   }
}