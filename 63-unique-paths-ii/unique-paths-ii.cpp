class Solution {
public:
   int f(int row,int col,int m,int n,vector<vector<int>>&dp,vector<vector<int>>&arr){
        if(row==m-1 && col==n-1){
            if(arr[row][col]==1){
                return 0;
            }
            else{
                return 1;
            }
        }
        if(row>=m || col >=n){
            return 0;
        }
        if(arr[row][col]==1){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        // down ->
      int x= f(row+1,col,m,n,dp,arr);
      // right ->
      int y= f(row,col+1,m,n,dp,arr);
      return dp[row][col]=x+y;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int m=obstacleGrid.size();
         int n=obstacleGrid[0].size();
         vector<vector<int>>dp(m,vector<int>(n,-1));
         return f(0,0,m,n,dp,obstacleGrid);
    }
};