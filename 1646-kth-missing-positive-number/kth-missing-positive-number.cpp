class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int start=0;
       int n=arr.size();
       int end=arr.size()-1;
       while(start<=end){
          int mid=start+(end-start)/2;
          if((arr[mid]-mid-1)<k){
              start=mid+1;
          }
          else{
               end=mid-1;
          }
       }
     int ans=k+end+1;
     return ans; 
    }
};