class Solution {
public:
   set<vector<int>>st;
    void f(vector<int>&nums,int index,vector<int>&ds){
        if(index==(nums.size())){
            st.insert(ds);
            return ;
        }
          ds.push_back(nums[index]);
          f(nums,index+1,ds);
          ds.pop_back();
          f(nums,index+1,ds);
      return;
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        f(nums,0,ds);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};