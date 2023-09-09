class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
      int ub=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
      int ans=lb+(ub-lb)/2;
      return ans;
    }
};