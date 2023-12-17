class Solution {
public:
     vector<vector<string>>ans;
     void f(string s,int idx,vector<string>path){
              if(idx==s.size()){
                  ans.push_back(path);
                  return ;
              }
              for(int i=idx;i<s.size();i++){
                 string x=s.substr(idx,i-idx+1);
                 string t=x;
                 reverse(x.begin(),x.end());
                 if(x==t){
                   path.push_back(t);
                   f(s,i+1,path);
                   path.pop_back();
                 }
              }
              return ;
     }
    vector<vector<string>> partition(string s) {
           vector<string>path;
           f(s,0,path);
           return ans;
    

    }
};