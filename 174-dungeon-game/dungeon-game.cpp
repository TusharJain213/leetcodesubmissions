class Solution {
public:
    int f(int row,int col,vector<vector<int>>&dungeon,int n,int m,vector<vector<int>>&dp){
          if(col>=m || row>=n){
               return 1e9;
          }
          if(dp[row][col]!=-1){
              return dp[row][col];
          }
          int x=min(f(row,col+1,dungeon,n,m,dp),f(row+1,col,dungeon,n,m,dp));
          if(x==1e9){
              x=1;
          }
              if(x-dungeon[row][col]<=0){
                  return dp[row][col]=1;
              }
              else{
                  return dp[row][col]=x-dungeon[row][col];
              }
          

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,dungeon,n,m,dp);
    }
};