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
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1);
	 int maxi=1;
	 for(int i=0;i<n;i++){
         for(int j=0;j<i;j++){
			 if(arr[i]>arr[j]){
				 dp[i]=max(1+dp[j],dp[i]);
				 maxi=max(maxi,dp[i]);
			 }
		 }
	 }
	 return maxi;
    }
};