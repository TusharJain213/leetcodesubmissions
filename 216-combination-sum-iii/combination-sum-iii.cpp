class Solution {
public: 
    vector<vector<int>>ans;
    void f(int k,int n,vector<int>temp,int i,int cnt){
       if(n<0){
           return;
       }
       if(n==0 && cnt==k){
           ans.push_back(temp);
           return ;
       }
       if(cnt==k){
           return;
       }
       if(i>9){
           return;
       }
       //not pick
       f(k,n,temp,i+1,cnt);
       //pick 
       temp.push_back(i);
       f(k,n-i,temp,i+1,cnt+1);
     return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        f(k,n,temp,1,0);
        return ans;
    }
};