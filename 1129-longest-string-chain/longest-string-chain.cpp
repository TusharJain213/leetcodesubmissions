   bool comp(string a,string b){
        return a.size()<b.size();
    }
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2,vector<vector<int>>&dp) {
        int n=text1.size();
        int m=text2.size();
          for(int i=0;i<=n;i++){
              dp[i][0]=0;
          }
          for(int i=0;i<=m;i++){
              dp[0][i]=0;
          }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    string ans="";
	longestCommonSubsequence(s1,s2,dp);
	int i=n;
	int j=m;
	while(i>0 && j>0){
         if(s1[i-1]==s2[j-1]){
			 ans=ans+s1[i-1];
			 i--;
			 j--;
		 }
		 else{
			 if(dp[i-1][j]>dp[i][j-1]){
				 i--;
			 }
			 else{
				 j--;
			 }
		 }
	}	
	reverse(ans.begin(),ans.end());
	return ans;	
}
    int longestStrChain(vector<string>& words) {
        int maxi=1;
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
               if(words[i].size()-words[j].size()==1){
                    string x=findLCS(words[i].size(),words[j].size(),words[i],words[j]);
                    if(x==words[j] && 1+dp[j]>dp[i]){
                       dp[i]=1+dp[j];
                       maxi=max(maxi,dp[i]);
                    }
               }               
            }
        }
        return maxi;
    }
};