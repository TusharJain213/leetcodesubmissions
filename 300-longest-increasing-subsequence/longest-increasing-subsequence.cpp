class Solution {
public:
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