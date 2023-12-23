class Solution {
public:
    // int f(int row,int col,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
    // if(row==n-1 && col==m-1){
    //     return grid[row][col];
    // }
    //   if(row>=n || col>=m){
    //       return 1e9;
    //   }
    //   if(dp[row][col]!=-1){
    //       return dp[row][col];
    //   }
    //   return dp[row][col]=grid[row][col]+min(f(row+1,col,n,m,grid,dp),f(row,col+1,n,m,grid,dp));
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--){
             for(int j=m-1;j>=0;j--){
               if(i==n-1 && j==m-1){
                   continue;
               }
               int x=1e9;
               int y=1e9;
               if(i+1<n){
                  x=dp[i+1][j];
               }
               if(j+1<m){
                   y=dp[i][j+1];
               }
               dp[i][j]=grid[i][j]+min(x,y);
             }
        }
        return dp[0][0];
    }
};