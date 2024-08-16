#include <bits/stdc++.h> 
using namespace std;

class heap 
    {
    public : 
        int arr[100];
        int size;

        heap(){
          arr[0] = -1;
          size=0;
        }

//insertion in heap (T.C-O(LogN))
        void insert(int val){
            size=size + 1;
            int index=size;
            arr[index]=val;

            while(index>1){
                int parent =index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }else{
                    return;
                }
            }
        }

        
     void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
            }
        cout<<endl;
        }



//deletion in heap(root node) (T.C-O(LogN))
void deletefromheap()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        // put last node element at root node
        arr[1] = arr[size];

        // remove lase node
        size--;

        // put root node at corect position
        int i = 1;

        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && rightIndex < size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if (rightIndex < size && arr[i] < arr[rightIndex] && arr[leftIndex] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }

            else
            {
                return;
            }
        }
    }

    };


//i=1 to n/2   T.C(O(LogN))
    void Maxheapify(int arr[],int n,int i){
        int largest=i;
        int left=2*i;
        int right=2*i +1;
        
        if(left<=n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n && arr[largest]<arr[right]){
            largest=right;
        }


        //update karna hai as tabhi hoga jab initial largest = i se koi change aayega
        if(largest!=i){
             swap(arr[i],arr[largest]);
             Maxheapify(arr,n,largest);
            }
    }


//T.C-(O(NLogN)) N for iterating through array and logn from the heapify function
void HeapSort(int arr[],int n){
    int size=n;
    while(size>=1){
    //step1 swap
        swap(arr[size],arr[1]);
        size--;
    //step2   
    Maxheapify(arr,size,1);
    }
}



 int main(){
        
        heap h;
        h.insert(50);
        h.insert(55);
        h.insert(53);
        h.insert(52);
        h.insert(54);
        h.print();

        h.deletefromheap();
        h.print();

        int arr[6]={-1,54,53,55,52,50};
        int n=5;

        cout<<"Printing the Original array now"<<endl;
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
        
        
        //MaxHeap
        for(int i=n/2;i>0;i--){
            Maxheapify(arr,n,i);
        }
        cout<<"Printing the MaxHeap array now"<<endl;
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;

        //HeapSort
        HeapSort(arr,n);

        cout<<"Printing the HeapSort array now"<<endl;
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;

 
 
 }