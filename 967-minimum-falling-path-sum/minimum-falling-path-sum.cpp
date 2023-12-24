class Solution {
public:
    //  int f(int row,int col,vector<vector<int>>&matrix,int n,vector<vector<int>>&dp){
    //      if(col<0 || col >=n || row>=n){
    //          return 1e9;
    //      }
    //      if(row==(n-1)){
    //          return matrix[row][col];
    //      }
    //      if(dp[row][col]!=-1){
    //          return dp[row][col];
    //      }
    //      return dp[row][col]=matrix[row][col]+min(f(row+1,col,matrix,n,dp),min(f(row+1,col+1,matrix,n,dp),f(row+1,col-1,matrix,n,dp))); 
    //  }
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n=matrix.size(); 
         vector<vector<int>>dp(n,vector<int>(n,-1));
         if(n==1){
             return matrix[0][0];
         }
    //      int mini=INT_MAX;
    //   for(int i=0;i<n;i++){
    //       mini=min(mini,matrix[0][i]+min(f(1,i,matrix,n,dp),min(f(1,i+1,matrix,n,dp),f(1,i-1,matrix,n,dp))));
    //   }
    //   return mini;
    for(int i=0;i<n;i++){
        dp[n-1][i]=matrix[n-1][i];
    }
    for(int i=n-2;i>=0;i--){
       for(int j=0;j<n;j++){
           int x=1e9;
           int y=1e9;
           int z=1e9;
           if(j-1>=0){
               x=dp[i+1][j-1];
           }
           if(j+1<n){
               y=dp[i+1][j+1];
           }
           z=dp[i+1][j];
           dp[i][j]=matrix[i][j]+min(x,min(y,z));
       } 
    }
   int ans=INT_MAX;
   for(int i=0;i<n;i++){
       ans=min(ans,dp[0][i]);
   }
   return ans;
    }
};