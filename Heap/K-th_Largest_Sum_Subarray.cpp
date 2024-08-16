#include <bits/stdc++.h> 
using namespace std;

// Approach 1 T.C-(O(N^2))  S.C-(O(N^2))
int getKthLargest(vector<int> &arr, int k)
{
	vector<int> ans;
	int n=arr.size();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum=sum+arr[j];
			ans.push_back(sum);
		}
	}
	sort(ans.begin(),ans.end());
	return (ans[ans.size()-k]);
}

// MiniHeap-s.c log(k)  aur MaxHeap ka s.c-log(n) thats why using MinHeap
// Approach 1 T.C-(O(N^2))  S.C-(O(N^2 logK))
#include <bits/stdc++.h> 
int getKthLargest(vector<int> &arr, int k)
{
 priority_queue<int,vector<int>,greater<int> > miniHeap;
	int n=arr.size();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum=sum+arr[j];
			if(miniHeap.size()<k){
				miniHeap.push(sum);
			}else{
                          if (sum > miniHeap.top()) {
                            miniHeap.pop();
                            miniHeap.push(sum);
                          }
                        }
                }
        }
		return miniHeap.top();
}