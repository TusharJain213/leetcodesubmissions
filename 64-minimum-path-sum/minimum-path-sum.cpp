class Solution {
public:
    int f(int row,int col,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(row==n-1 && col==m-1){
        return grid[row][col];
    }
      if(row>=n || col>=m){
          return 1e9;
      }
      if(dp[row][col]!=-1){
          return dp[row][col];
      }
      return dp[row][col]=grid[row][col]+min(f(row+1,col,n,m,grid,dp),f(row,col+1,n,m,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,n,m,grid,dp);
    }
};