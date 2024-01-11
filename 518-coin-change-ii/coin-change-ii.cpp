class Solution {
public:
    int f(int idx,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(amount==0){
            return 1;
        }
        if(idx==coins.size()){
            return 0;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
//pick:->
int pick=0;
if(coins[idx]<=amount){
    pick=f(idx,coins,amount-coins[idx],dp);
}
int notpick=f(idx+1,coins,amount,dp);
return dp[idx][amount]=pick+notpick;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(0,coins,amount,dp);
    }
};