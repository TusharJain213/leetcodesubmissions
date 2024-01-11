class Solution {
public:
    int f(int idx,vector<int>&coins,int amount,vector<vector<int>>&dp){
       if(idx==coins.size()-1){
           if(amount%coins[idx]==0){
               return amount/coins[idx];
           }
           else{
               return 1e9;
           }
       }
       if(dp[idx][amount]!=-1){
           return dp[idx][amount];
       }
       //Pick->:
       int pick=1e9;
       if(coins[idx]<=amount){
           pick=1+f(idx,coins,amount-coins[idx],dp);
       }
       int notpick=f(idx+1,coins,amount,dp);
       return dp[idx][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(0,coins,amount,dp);
        if(ans==1e9){
            return -1;
        }
        else{
            return ans;
        }
    }
};