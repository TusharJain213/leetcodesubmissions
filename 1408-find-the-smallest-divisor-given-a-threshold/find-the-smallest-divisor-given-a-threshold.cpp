class Solution {
public:
     bool f(int a,vector<int>&nums,int threshold){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=ceil((double)nums[i]/a);
        }
        if(cnt>threshold){
            return false;
        }
        else{
            return true;
        }
     }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1;
        int end=*max_element(nums.begin(),nums.end());
        int ans;
        while(start<=end){
           int mid=start+(end-start)/2;
           if(f(mid,nums,threshold)){
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