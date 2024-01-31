class Solution {
public:
    int f(int idx,int last,vector<int>&nums,vector<vector<int>>&dp){
         if(idx==nums.size()){
            return 0;
         }
         if(dp[idx][last+1]!=-1){
             return dp[idx][last+1];
         }
        int x=f(idx+1,last,nums,dp);
        int y=0;
       if(last==-1||nums[idx]>nums[last]){
             y=1+f(idx+1,idx,nums,dp);
       }
       return dp[idx][last+1]=max(x,y);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};