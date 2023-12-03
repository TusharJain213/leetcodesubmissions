class Solution {
public:
     vector<vector<int>>ans;
    void f(vector<int>combinations,int target,vector<int>x,int index){
            if(index==combinations.size()||target<0){
                 return ;
            }
           if(target==0){
             ans.push_back(x);
             x.clear();
             return;
           }
     
     //take
     x.push_back(combinations[index]);
     f(combinations,target-combinations[index],x,index);
     // Not take
     x.pop_back();
     f(combinations,target,x,index+1);
     return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>temp;
        f(candidates,target,temp,0);
        return ans;
    }
};