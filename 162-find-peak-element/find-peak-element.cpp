class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=1;
        int n=nums.size();
        int end=n-2;
        int ans;
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1]){
             return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        while(start<=end){
           int mid=start+(end-start)/2;
           if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]){
               ans=mid;
               break;
           }
           else{
             if(nums[mid+1]>nums[mid]){
                 start=mid+1;
             }
             else{
                 if(nums[mid-1]>nums[mid]){
                     end=mid-1;
                 }
             }
           }
        }
        return ans;
    }
};