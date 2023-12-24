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

    #include <vector>

bool canPartition(std::vector<int>& nums) {
    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    if (sum % 2 != 0 || n == 1) {
        return false;
    }

    std::vector<std::vector<bool>> dp(n, std::vector<bool>(sum / 2 + 1, false));

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= sum / 2; j++) {
            if (j >= nums[i]) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n - 1][sum / 2];
}

};
