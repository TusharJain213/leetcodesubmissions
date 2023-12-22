class Solution {
public:
    int f(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx >= nums.size()) {
            return 0;
        }

        // Check if the value for idx is already computed
        if (dp[idx] != -1) {
            return dp[idx];
        }

        // Either pick the current house and skip the next, or skip the current house
        int pick = nums[idx] + f(idx + 2, nums, dp);
        int skip = f(idx + 1, nums, dp);

        // Store the result in dp
        dp[idx] = max(pick, skip);

        return dp[idx];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp);
    }
};
