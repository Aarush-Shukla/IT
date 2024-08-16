#include <bits/stdc++.h> 
using namespace std;

class Queue {

       int *arr;
       int size;
       int qfront;
       int rear;
public:
    Queue() {
      size=100001;
      arr=new int[size];
      qfront=0;
      rear=0;
}

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront==rear){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int data) {
        //check overflow
        if(rear==size){
            cout<<"Queue is full "<<endl;
        }else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {
        if (qfront==rear){
            return -1;
        }else{
  int ans=arr[qfront];
        arr[qfront]=-1;
        qfront++;
        if (rear == qfront) {
          qfront = 0;
          rear = 0;
        }

        return ans;
        }
    }

    int front() {
        if(qfront==rear){
            return -1;
        }else{
            return arr[qfront];
        }
    }
};