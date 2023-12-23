class Solution {
public:
    // int f(int row,int col,int m,int n,vector<vector<int>>&dp){
    //     if(row==m-1 && col==n-1){
    //         return 1;
    //     }
    //     if(row>=m || col >=n){
    //         return 0;
    //     }
    //     if(dp[row][col]!=-1){
    //         return dp[row][col];
    //     }
    //     // down ->
    //   int x= f(row+1,col,m,n,dp);
    //   // right ->
    //   int y= f(row,col+1,m,n,dp);
    //   return dp[row][col]=x+y;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                  if(i==m-1 && j==n-1){
                      continue;
                  }
                   int x=0;
                   int y=0;
                   if(i+1<m){
                      x=dp[i+1][j];
                   }
                   if(j+1<n){
                       y=dp[i][j+1];
                   }
                   dp[i][j]=x+y;
            }
        }
      return dp[0][0];
    }
};