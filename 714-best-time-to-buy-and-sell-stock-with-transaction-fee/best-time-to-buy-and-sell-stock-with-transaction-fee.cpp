class Solution {
public:
      int f(int idx,vector<int>&prices,int buy,vector<vector<int>>&dp,int fee){
        if(prices.size()==idx){
            return 0;
        }
      if(dp[idx][buy]!=-1){
          return dp[idx][buy];
      }
      int profit=0;
      if(buy){
        profit=max(-prices[idx]+f(idx+1,prices,0,dp,fee)-fee,f(idx+1,prices,1,dp,fee));
      }
      else{
          profit=max(prices[idx]+f(idx+1,prices,1,dp,fee),f(idx+1,prices,0,dp,fee));
      }
      return dp[idx][buy]=profit;

    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(0,prices,1,dp,fee);
    }
};