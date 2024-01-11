class Solution {
public:
    // int f(int idx,vector<int>&coins,int amount,vector<vector<int>>&dp){
    //    if(idx==coins.size()-1){
    //        if(amount%coins[idx]==0){
    //            return amount/coins[idx];
    //        }
    //        else{
    //            return 1e9;
    //        }
    //    }
    //    if(dp[idx][amount]!=-1){
    //        return dp[idx][amount];
    //    }
    //    //Pick->:
    //    int pick=1e9;
    //    if(coins[idx]<=amount){
    //        pick=1+f(idx,coins,amount-coins[idx],dp);
    //    }
    //    int notpick=f(idx+1,coins,amount,dp);
    //    return dp[idx][amount]=min(pick,notpick);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        for(int tar=0;tar<=amount;tar++){
            if(tar%coins[0]==0){
                dp[0][tar]=tar/coins[0];
            }
        }
        for(int i=1;i<n;i++){
           for(int tar=0;tar<=amount;tar++){
                int pick=1e9;
                if(coins[i]<=tar){
                    pick=1+dp[i][tar-coins[i]];
                }
                int notpick=dp[i-1][tar];
                dp[i][tar]=min(pick,notpick);
           }
        }
        int ans=dp[n-1][amount];
        if(ans>=1e9){
            return -1;
        }
        else{
            return ans;
        }
    }
};