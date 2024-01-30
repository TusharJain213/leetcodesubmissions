class Solution {
public:
    int mod=(int)1e9+7;
    int numTilings(int n) {
        vector< long long int>dp(n+1,0);
        if(n==1){
            return 1;
        }
        else{
            if(n==3){
                return 5;
            }
            else{
                if(n==2){
                    return 2;
                }
             }
            }
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++){
            dp[i]=(2*dp[i-1]+dp[i-3])%mod;
        }
        return dp[n]%mod;
    }
};