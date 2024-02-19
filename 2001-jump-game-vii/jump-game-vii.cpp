#include <vector>
#include <string>

class Solution {
public:
    bool canReach(string& s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;

        int prefixSum = 0;

        for (int i = 1; i < n; ++i) {
            if (i >= minJump) {
                prefixSum += dp[i - minJump];
            }
            if (i > maxJump) {
                prefixSum -= dp[i - maxJump - 1];
            }

            dp[i] = (s[i] == '0' && prefixSum > 0);
        }

        return dp[n - 1] > 0;
    }
};
