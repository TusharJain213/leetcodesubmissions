class Solution {
public:
    // int f(int idx, vector<int>& nums, vector<int>& dp) {
    //     if (idx >= nums.size()) {
    //         return 0;
    //     }

        
    //     if (dp[idx] != -1) {
    //         return dp[idx];
    //     }

       
    //     int pick = nums[idx] + f(idx + 2, nums, dp);
    //     int skip = f(idx + 1, nums, dp);

       
    //     dp[idx] = max(pick, skip);

    //     return dp[idx];
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0]=nums[0];
        if(nums.size()==1){
            return dp[0];
        }
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
          //pick->
          int x=nums[i]+dp[i-2];
          int y=dp[i-1];
          dp[i]=max(x,y);
        }
        return dp[n-1];
    }
};
