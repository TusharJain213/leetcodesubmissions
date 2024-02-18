class Solution {
public:
     bool f(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size()-1){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
      for(int i=1;i<=nums[idx];i++){
          if(f(idx+i,nums,dp)){
              return dp[idx]=true;
          }
      }
      return dp[idx]=false;
     }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};