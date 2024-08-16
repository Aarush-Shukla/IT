    #include <bits/stdc++.h> 
using namespace std; 

long long int BinarySearch(int n){
    int s=0;
    int e=n;
    long long int mid=s +(e-s)/2;
    long long int ans=-1;
    
    while(s<=e){
        long long int square=mid*mid;
        if(n==square){
            return mid;
        }
        if (square<n){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    mid=s +(e-s)/2;

    }

    return ans;
}




int floorSqrt(int n)
{
    return BinarySearch(n);
}

double precison(int n,int NoOfDecimal,double tempsol){
    double ans=tempsol;
    double factor=1;
     for(int i=0;i<NoOfDecimal;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
     }
     return ans;
}

int main(){
    int n;
    cin>>n;
    int NoOfDecimal;
    cin>>NoOfDecimal;
int tempsol=floorSqrt(n);
cout<< precison(n,NoOfDecimal,tempsol)<<endl;
}