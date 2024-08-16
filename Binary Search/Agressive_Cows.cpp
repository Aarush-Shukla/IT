int isPossible(vector<int> &stalls, int k,int mid){
int CowCount=1;
int LastPos=stalls[0];
for(int i=0;i<stalls.size();i++){
 if(stalls[i]-LastPos>=mid){
     CowCount++;
     if(CowCount==k){
         return true;
     }
     LastPos=stalls[i];
 }

}
return false;
}



int aggressiveCows(vector<int> &stalls, int k)
{
   sort(stalls.begin(),stalls.end());
   int s=0;
   int maxi=-1;
   for(int i=0;i<stalls.size();i++){
       maxi=max(maxi,stalls[i]);
   }
   int e=maxi;
   int mid= s+ (e-s)/2;
   int ans=-1;

   while(s<=e){
       if(isPossible(stalls,k,mid)){
              ans=mid;
              s=mid+1;
       }else{
           e=mid-1;
       }
       mid= s+ (e-s)/2;
   }
   return ans;
}