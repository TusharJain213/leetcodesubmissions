class Solution {
public:
    bool f(long long a,vector<int>piles,int k){
      long long cnt=0;
      for(long long i=0;i<piles.size();i++){
          cnt+=ceil((double)piles[i]/a);
      }
      if(cnt>k){
          return false;
      }
      else{
          return true;
      }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long ans;
        sort(piles.begin(),piles.end());
        long long start=1;
        long long end=piles[piles.size()-1];
        while(start<=end){
           long long mid=start+(end-start)/2;
           if(f(mid,piles,h)){
               ans=mid;
               end=mid-1;
           }
           else{
               start=mid+1;
           }
        }
        return ans;
    }
};