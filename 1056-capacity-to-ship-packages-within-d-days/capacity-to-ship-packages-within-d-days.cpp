class Solution {
public:
    bool f(int a,vector<int>weights,int k){
        int cnt=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>a){
                return false;
            }
            sum+=weights[i];
              if(sum>a){
                  sum=weights[i];
                  cnt++;
              }          
        }
        if(cnt<=k){
            return true;
        }
        else{
            return false;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start=0;
        int end=accumulate(weights.begin(),weights.end(),0);
        int ans;
        while(start<=end){
          int mid=start+(end-start)/2;
          if(f(mid,weights,days)){
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