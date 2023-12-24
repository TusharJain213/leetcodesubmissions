#include <vector>
#include <algorithm>

class Solution {
public:
    int f(int idx, int last, std::vector<std::vector<int>>& triangle,vector<vector<int>>&dp) {
        if (idx == (triangle.size() - 1)) {
            return min(triangle[idx][last],triangle[idx][last+1]);
        }
        if(dp[idx][last]!=-1){
            return dp[idx][last];
        }
        if (idx == 0) {
            return triangle[idx][last] + f(idx + 1, last, triangle,dp);
        } else {
           int x=triangle[idx][last] + f(idx + 1, last, triangle,dp);
           int y=triangle[idx][last+1]+f(idx + 1, last + 1, triangle,dp);
           return dp[idx][last]=min(x,y);
        }
    }

    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        if(n==1){
            return triangle[0][0];
        }
        return f(0, 0, triangle,dp);
    }
};
