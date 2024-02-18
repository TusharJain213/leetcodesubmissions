class Solution {
public:
    int f(int idx,string s,vector<int>&dp){
     if(idx>=s.size()){
         return 1;
     }
     if(s[idx]=='0'){
         return 0;
     }
     if(dp[idx]!=-1){
         return dp[idx];
     }
     int cnt1=f(idx+1,s,dp);
     int cnt2=0;
     if(idx<s.size()-1 && stoi(s.substr(idx,2))<=26){
        cnt2=f(idx+2,s,dp);
     }
     return dp[idx]=cnt1+cnt2;

    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return f(0,s,dp);
    }
};