class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int start=0;
         int end=nums.size()-1;
         int fo=-1;
         int lo=-1;
         while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                 fo=mid;
                 end=mid-1;
            }
            else{
             if(nums[mid]>target){
                 end=mid-1;
             }
             else{
                 start=mid+1;
             }
            }
         }
         start=0;
         end=nums.size()-1;
            while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                 lo=mid;
                 start=mid+1;
            }
            else{
             if(nums[mid]>target){
                 end=mid-1;
             }
             else{
                 start=mid+1;
             }
            }
         }
         vector<int>ans;
         ans.push_back(fo);
         ans.push_back(lo);
         return ans;
    }
};