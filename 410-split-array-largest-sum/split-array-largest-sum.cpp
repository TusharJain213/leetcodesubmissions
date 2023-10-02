class Solution {
public:
    bool f(int a,vector<int>&nums,int k){
        int sum=0;
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+sum<=a){
                  sum+=nums[i];
            }
            else{
                cnt++;
                sum=nums[i];
            }
        }
        if(cnt<=k){
            return true;
        }
        else{
            return false;
        }
    }
    int splitArray(vector<int>& nums, int k) {
       int start=*max_element(nums.begin(),nums.end());
       int end=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(f(mid,nums,k)){
                 end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
     return start;
    }
};