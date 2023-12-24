class Solution {
public:
    bool f(vector<int>& nums, int idx, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        if (idx == nums.size()) {
            return false;
        }
        if (target < 0) {
            return false;
        }

        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }

        // pick ->
        bool x = f(nums, idx + 1, target - nums[idx], dp);
        // not pick ->
        bool y = f(nums, idx + 1, target, dp);

        return dp[idx][target] = x || y;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }

        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum,-1));

        return f(nums, 0, sum / 2, dp);
    }
};
