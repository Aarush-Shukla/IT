#include<bits/stdc++.h>
using namespace std;
// vector<int> findMedian(vector<int> &arr, int n){
	
	
//   t.c is n^2log(n);
//   s.c is n;

	//  vector<int>ans;
	//  vector<int>v;
	
	//  for(int i=0; i<n; i++){
	// 	 v.push_back(arr[i]);
         
	// 	 sort(v.begin(), v.end());
	// 	 int size = v.size();
	// 	  int index = size/2;
	// 	 if(size % 2== 0){
			
    //         int temp = (v[index] + v[index-1])/2;
	// 		ans.push_back(temp);
	// 	 }
	// 	 else{
    //              ans.push_back(v[index]);
	// 	 }
	//  }
	//  return ans;
    // }




//Approach 2-// optimise solution
// t.c is nlogn
// s.c is n;


int signum(int a,int b){
	if(a==b){
		return 0;
	}else if(a>b){
		return 1;
	}else{
		return -1;
	}
}

void callMedian(int element,priority_queue<int,vector<int>,greater<int>> &mini,priority_queue<int> &maxi,int &median){

    switch(signum(maxi.size(),mini.size())){
		
		
		case 0: if(element>median){

				mini.push(element);
				median=mini.top();
		 	}else{

				maxi.push(element);
				median=maxi.top();

		 	}

			 break;

    

	    case 1: if(element>median){

				mini.push(element);
				median=(mini.top()+maxi.top())/2;

			}else{

				mini.push(maxi.top());
				maxi.pop();
				maxi.push(element);
				median=(mini.top()+maxi.top())/2;

			}

			break;


        case -1: if(element>median){
			        maxi.push(mini.top());
					mini.pop();
					mini.push(element);
					median=(mini.top()+maxi.top())/2;

				}else{

					maxi.push(element);
					median=(mini.top()+maxi.top())/2;

					}
				
				break;
	
	}
                       
}


vector<int> findMedian(vector<int> &arr, int n){
	
    vector<int>ans;
	priority_queue<int,vector<int>,greater<int>> MinHeap;
	priority_queue<int> MaxHeap;

	int median=0;
	for(int i=0;i<n;i++){
		callMedian(arr[i],MinHeap,MaxHeap,median);
		ans.push_back(median);
	}
	return ans;

}


