class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int n = prices.size();
        int minbuy = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            minbuy = min(minbuy, prices[i]);
            maxprofit = max(maxprofit, prices[i]-minbuy);
        }
        return maxprofit;
        
    }
};