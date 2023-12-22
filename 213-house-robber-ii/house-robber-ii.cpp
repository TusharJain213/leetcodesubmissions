class Solution {
public:
      int f(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0]=nums[0];
        if(nums.size()==1){
            return dp[0];
        }
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
          //pick->
          int x=nums[i]+dp[i-2];
          int y=dp[i-1];
          dp[i]=max(x,y);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
         vector<int>temp1;
         vector<int>temp2;
         for(int i=0;i<nums.size();i++){
             if(i!=0){
                 temp1.push_back(nums[i]);
             }
             if(i!=nums.size()-1){
                 temp2.push_back(nums[i]);
             }
         }
         return max(f(temp1),f(temp2));

    }
};