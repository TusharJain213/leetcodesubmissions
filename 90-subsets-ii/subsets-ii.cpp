class Solution {
public: 
    void f(int index,vector<int>&ds,vector<vector<int>>&result,vector<int>&nums){
        result.push_back(ds);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            f(i+1,ds,result,nums);
            ds.pop_back();
        }
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>>result;
         sort(nums.begin(),nums.end());
         vector<int>ds;
         f(0,ds,result,nums);
         return result;
    }
};