class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int x=1e9;
        vector<int>mini(prices.size(),-1);
       for(int i=0;i<prices.size();i++){
           mini[i]=x;
           x=min(x,prices[i]);
       }
       for(int i=0;i<prices.size();i++){
           maxi=max(maxi,prices[i]-mini[i]);
       }
       return maxi;
    }
};