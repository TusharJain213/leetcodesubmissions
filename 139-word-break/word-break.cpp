#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Empty string can be broken

        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    string word = s.substr(j, i - j);
                    if (wordSet.find(word) != wordSet.end()) {
                        dp[i] = true;
                        break; // Move to the next i
                    }
                }
            }
        }

        return dp[n];
    }
};
