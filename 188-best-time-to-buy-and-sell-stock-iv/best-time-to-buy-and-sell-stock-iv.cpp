class Solution {
public:
     int f(int idx,vector<int>&prices,int buy,int cnt,vector<vector<vector<int>>>&dp){
        if(prices.size()<=idx){
            return 0;
        }
      if(cnt==0){
          return 0;
      }
      if(dp[idx][buy][cnt]!=-1){
          return dp[idx][buy][cnt];
      }
      int profit=0;
      if(buy){
        profit=max(-prices[idx]+f(idx+1,prices,0,cnt,dp),f(idx+1,prices,1,cnt,dp));
      }
      else{
          profit=max(prices[idx]+f(idx+1,prices,1,cnt-1,dp),f(idx+1,prices,0,cnt,dp));
      }
      return dp[idx][buy][cnt]=profit;

    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,prices,1,k,dp);
    }
};