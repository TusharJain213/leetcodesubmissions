class Solution {
public:
    vector<string>ans;
    void f(string digits,int n,int index,unordered_map<int,string>mpp,string &temp){
            if(n==0){
                return;
            }
            if(index>=n){
                ans.push_back(temp);
                return;
            }
           string x=mpp[digits[index]-'0'];
           for(int i=0;i<x.size();i++){
               temp.push_back(x[i]);
               f(digits,n,index+1,mpp,temp);
               temp.pop_back();
           }
           return;
    }
    vector<string> letterCombinations(string digits) {
       int n=digits.size();
       unordered_map<int,string>mpp;
       mpp[2]="abc";
       mpp[3]="def";
       mpp[4]="ghi";
       mpp[5]="jkl";
       mpp[6]="mno";
       mpp[7]="pqrs";
       mpp[8]="tuv";
       mpp[9]="wxyz";
       string temp;
       f(digits,n,0,mpp,temp);

     return ans;


    }
};