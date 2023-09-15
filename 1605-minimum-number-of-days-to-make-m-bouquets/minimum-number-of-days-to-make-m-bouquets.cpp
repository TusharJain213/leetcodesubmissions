class Solution {
public:
      bool f(int a, int m, int k, vector<int>& bloomday) {
        vector<char> s(bloomday.size(), '_'); // Initialize a vector of '_' characters
        
        for (int i = 0; i < bloomday.size(); i++) {
            if (bloomday[i] <= a) {
                s[i] = 'x';
            }
        }
        
        int p = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'x') {
                p++;
            } else {
                p = 0;
            }
            
            if (p == k) {
                cnt++;
                p = 0;
            }
        }
        
        return cnt >= m;
    }
    int minDays(vector<int>& bloomday, int m, int k) {
        int start=1;
        int end=*max_element(bloomday.begin(),bloomday.end());
        int ans=-1;
        while(start<=end){
           int mid=start+(end-start)/2;
           if(f(mid,m,k,bloomday)){
                ans=mid;
                end=mid-1;
           }
           else{
               start=mid+1;
           }
        }
        return ans;
  }
};