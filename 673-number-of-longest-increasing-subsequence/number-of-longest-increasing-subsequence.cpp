class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
	 for(int i=0;i<n;i++){
         for(int j=0;j<i;j++){
			  if(arr[i]>arr[j]){
                  if(dp[i]==1+dp[j]){
                      cnt[i]+=cnt[j];
                  }
                  else{
                      if(dp[i]<dp[j]+1){
                          dp[i]=1+dp[j];
                          cnt[i]=cnt[j];
                      }
                  }
              }
		 }
	 }
       int max=*max_element(dp.begin(),dp.end());
         int ans=0;
         for(int i=0;i<n;i++){
             if(dp[i]==max){
                 ans+=cnt[i];
             }
         }
         return ans;
    }
};