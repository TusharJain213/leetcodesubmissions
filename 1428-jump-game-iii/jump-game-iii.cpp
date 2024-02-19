class Solution {
public:
    bool f(int idx,vector<int>&arr,vector<int>&visited,vector<int>&dp){
        if(idx<0 || idx>=arr.size()){
            return false;
        }
       if(arr[idx]==0){
           return true;
       }
       if(dp[idx]!=-1){
           return dp[idx];
       }
       if(visited[idx]){
           return false;
       }
       visited[idx]=1;
       if((f(idx-arr[idx],arr,visited,dp)||f(idx+arr[idx],arr,visited,dp))){
           return dp[idx]=true;
       }
       else{
           return dp[idx]=false;
       }
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>visited(arr.size(),0);
        vector<int>dp(arr.size(),-1);
        return f(start,arr,visited,dp);
    }
};