class Solution {
public:
    vector<int>ans;
    void f(int index,vector<int>&nums,vector<vector<int>>&result){
        if(index>=nums.size()){
            result.push_back(ans);
            return ;
        }
        ans.push_back(nums[index]);
        f(index+1,nums,result);
        ans.pop_back();
        f(index+1,nums,result);
      return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        f(0,nums,result);
        return result;
    }
};