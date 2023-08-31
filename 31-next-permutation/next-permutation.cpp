class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx;
        int n=nums.size();
        for(idx=n-2;idx>=0;idx--){
            if(nums[idx]<nums[idx+1]){
                break;
            }
        }
        if(idx==-1){
            sort(nums.begin(),nums.end());
            return ;
        }
        int l;
        for(l=n-1;l>idx;l--){
            if(nums[l]>nums[idx]){
                swap(nums[l],nums[idx]);
                break;
            }
        }
        sort(nums.begin()+idx+1,nums.end());
        return ;



    }
};