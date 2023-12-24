#include <vector>
#include <algorithm>

class Solution {
public:
    // int f(int idx, int last, std::vector<std::vector<int>>& triangle,vector<vector<int>>&dp) {
    //     if (idx == (triangle.size() - 1)) {
    //         return min(triangle[idx][last],triangle[idx][last+1]);
    //     }
    //     if(dp[idx][last]!=-1){
    //         return dp[idx][last];
    //     }
    //     if (idx == 0) {
    //         return triangle[idx][last] + f(idx + 1, last, triangle,dp);
    //     } else {
    //        int x=triangle[idx][last] + f(idx + 1, last, triangle,dp);
    //        int y=triangle[idx][last+1]+f(idx + 1, last + 1, triangle,dp);
    //        return dp[idx][last]=min(x,y);
    //     }
    // }

    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        if(n==1){
            return triangle[0][0];
        }
        for(int i=0;i<n;i++){
          dp[n-1][i]=triangle[n-1][i];   
        }
        for(int i=n-2;i>=0;i--){
             for(int j=0;j<triangle[i].size();j++){
                 int x,y;
                 x=triangle[i][j]+dp[i+1][j];
                 y=triangle[i][j]+dp[i+1][j+1];
                 dp[i][j]=min(x,y);
             }
        }
        return dp[0][0];
    }
};
