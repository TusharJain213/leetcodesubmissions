class Solution {
public:
    bool ans=false;
    void f(vector<vector<char>>&board,string word,int idx,vector<vector<bool>>&visited,int row,int col){
        if(idx==word.size()){
            ans=true;
            return;
        }
        visited[row][col]=true;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=drow[i]+row;
            int ncol=dcol[i]+col;
          if(nrow>=0 && ncol>=0 && nrow<board.size() && ncol< board[0].size() && !visited[nrow][ncol] && board[nrow][ncol]==word[idx]){
              f(board,word,idx+1,visited,nrow,ncol);
          }
        }
        visited[row][col]=false;
        return;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vector<vector<bool>>visited(m,vector<bool>(n,false));
                    f(board,word,1,visited,i,j);
                }
            }
        }
        return ans;


    }
};