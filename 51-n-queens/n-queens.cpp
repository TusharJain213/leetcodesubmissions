class Solution {
public:
    vector<vector<string>>ans;
     bool issafe(int row,int col,vector<string>path){
       int drow=row;
       int dcol=col;
       while(col>=0){
           if(path[row][col]=='Q'){
               return false;
           }
           col--;
       }  
       col=dcol;
       while(row>=0 && col>=0 ){
           if(path[row][col]=='Q'){
               return false;
           }
           row--;
           col--;
       }
       row=drow;
       col=dcol;
       while(row<path.size() && col>=0){
           if(path[row][col]=='Q'){
               return false;
           }
           row++;
           col--;
       }
       return true;
     }
     void f(int col,vector<string>path,int n){
       if(col==n){
           ans.push_back(path);
           return;
       }
       for(int i=0;i<n;i++){
           if(issafe(i,col,path)){
               path[i][col]='Q';
               f(col+1,path,n);
               path[i][col]='.';
           }
       }
     return ;
     }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>path(n);
        string s(n,'.');
        vector<vector<int>>visited(n,vector<int>(n,false));
        for(int i=0;i<n;i++){
            path[i]=s;
        }
        f(0,path,n);
        return ans;
    }
};