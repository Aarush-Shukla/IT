#include<iostream>
using namespace std;

int Power(int a,int b){
    //Base Case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans=Power(a,b/2);
    if(b%2==0){
        return ans*ans;
    }
    if(b%2!=0){
        return a*ans*ans;
    }
}
int main(){
    cout<< Power(3,11)<<endl;
}