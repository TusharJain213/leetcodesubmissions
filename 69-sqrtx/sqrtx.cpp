class Solution {
public:
    int mySqrt(int n) {
     long long start=0;
     long long end=n;
     long long ans;
     while(start<=end){
       long long  mid=start+(end-start)/2;
       long long  square=mid*mid;
       if(square==n){
           return mid;
       } 
        if(square>n){
            end=mid-1;
            ans=end;
        }
        else{
            start=mid+1;
        }
     }
     return ans;
    }
};