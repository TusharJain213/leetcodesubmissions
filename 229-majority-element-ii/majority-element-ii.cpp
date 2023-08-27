class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int x=n/3;
        int majority1=INT_MIN;
        int count1=0;
        int count2=0;
        int majority2=INT_MIN;
        //Extended Moore's Voting Algorithm:-------->
        for(int i=0;i<n;i++){
            if(count1==0&&majority2!=nums[i]){
                count1++;
                majority1=nums[i];
            }
            else{
                if(count2==0&&majority1!=nums[i]){
                    count2++;
                    majority2=nums[i];
                }
                else{
                    if(nums[i]==majority1){
                        count1++;
                    }

                    else {
                       if(nums[i]==majority2){
                          count2++;
                        }
                        else{
                            count1--;
                            count2--;
                        }
                    }
                }
            }
        }
         vector<int>ans;
         count1=0;
         count2=0;
         for(int i=0;i<n;i++){
             if(majority1==nums[i]){
                 count1++;
             }
             if(majority2==nums[i]){
                 count2++;
             }
         }
         if(count1>x){
             ans.push_back(majority1);
         }
         if(count2>x){
             ans.push_back(majority2);
         }
         return ans;

        
    }
};