#include <bits/stdc++.h> 
using namespace std;

bool isPosible(vector<int> time, int n, int m,int mid){
	int StudentCount=1;
	int PageSum=0;
	for(int i=0;i<n;i++){
		if(PageSum+time[i]<mid){
			PageSum+=time[i];
		}else{
			StudentCount++;
			if(StudentCount>m || time[i]>mid){
				return false;
			}
			PageSum=0;
			PageSum+=time[i];
		}
	}
	return true;
}

long long ayushGivesNinjatest(vector<int> time, int n, int m) 
{	
	int s=0;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=time[i];
    }
	int e=sum;
	int ans=-1;

	int mid= s+ (e-s)/2;
	 while(s<=e){
        if(isPosible(time,n,m,mid)){
			ans=mid;
			e=mid-1;
		} else{
			s=mid+1;
		}
		mid= s+ (e-s)/2;
	 }
	 return ans;
}