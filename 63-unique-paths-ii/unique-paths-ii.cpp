class Solution {
public:
//    int f(int row,int col,int m,int n,vector<vector<int>>&dp,vector<vector<int>>&arr){
//         if(row==m-1 && col==n-1){
//             if(arr[row][col]==1){
//                 return 0;
//             }
//             else{
//                 return 1;
//             }
//         }
//         if(row>=m || col >=n){
//             return 0;
//         }
//         if(arr[row][col]==1){
//             return 0;
//         }
//         if(dp[row][col]!=-1){
//             return dp[row][col];
//         }
//         // down ->
//       int x= f(row+1,col,m,n,dp,arr);
//       // right ->
//       int y= f(row,col+1,m,n,dp,arr);
//       return dp[row][col]=x+y;
//     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int m=obstacleGrid.size();
         int n=obstacleGrid[0].size();
         if(obstacleGrid[m-1][n-1]==1){
             return 0;
         }
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                  if(i==m-1 && j==n-1){
                      continue;
                  }
                  if(obstacleGrid[i][j]==1){
                      dp[i][j]=0;
                      continue;
                  }
                   long int x=0;
                  long  int y=0;
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