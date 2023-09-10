class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0;
        int n=nums.size();
        int end=n-1;
        while(start<=end){
           int mid=start+(end-start)/2;
           if(nums[mid]==target){
              return true;
           }
          if(nums[mid]==nums[start]&&nums[mid]==nums[end]){
               end--;
               start++;
               continue;
           }
            if(nums[start]<=nums[mid]){
                if(target>=nums[start]&&target<=nums[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
              if(target<=nums[end]&&target>=nums[mid]){
                  start=mid+1;
              }
              else{
                  end=mid-1;
              }
            }
           }
        return false;
    }
};