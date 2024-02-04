class Solution {
public:
    // MY WAY->
    //STRIVER HAS DONE IN 2d-DP
    // int f(int idx,vector<int>&prices,int flag,int last,vector<vector<vector<int>>>&dp){
    //     if(idx==prices.size()){
    //         return 0;
    //     }
    //    if(last!=-1 && dp[idx][last][flag]!=-1){
    //        return dp[idx][last][flag];
    //    }
    //    //buy->
    //    int x=0;
    //    int y=0;
    //    if(!flag){
    //      x=f(idx+1,prices,1,idx,dp);
    //      y=f(idx+1,prices,0,last,dp);
    //    }
    //    else{
    //        if(prices[idx]>prices[last]){
    //            x=prices[idx]-prices[last]+f(idx+1,prices,0,-1,dp);
    //        }
    //        y=f(idx+1,prices,1,last,dp);
    //    }
    //    if(last!=-1){
    //    dp[idx][last][flag]=max(x,y);
    //    }
    //    return max(x,y);
    // } 
    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(prices.size(),vector<int>(2,-1)));
        // return f(0,prices,false,-1,dp);
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        int n=prices.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(!j){
                     dp[i][j]=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                else{
                    dp[i][j]=max(prices[i]+dp[i+1][0],dp[i+1][1]);
                }
            }
        }
        return dp[0][0];
    }
};