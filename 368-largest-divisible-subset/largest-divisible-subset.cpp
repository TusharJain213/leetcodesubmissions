class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      sort(nums.begin(),nums.end());
       int n=nums.size();
       vector<int>ans;
       vector<int>hash(n,0);
       for(int i=0;i<n;i++){
           hash[i]=i;
       }
       vector<int>dp(n,1);
       int last=0;
       int maxi=1;
       for(int i=0;i<n;i++){
           for(int j=0;j<i;j++){
               if(nums[i]%nums[j]==0){
                   if(dp[j]+1>dp[i]){
                       dp[i]=1+dp[j];
                       hash[i]=j;
                   }
                    if(dp[i]>maxi){
                           maxi=dp[i];
                           last=i;
                     }
               }
           }
       }
       ans.push_back(nums[last]);
       while(last!=hash[last]){
           ans.push_back(nums[hash[last]]);
           last=hash[last];
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};