class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/208241/Explanation-for-the-dummy-like-me.
        
        // how is this question differet from first variation?
        // here you can have as many number of transactions you want.
        // earlier you had only one transaction
        // now, you can have as many transactions to maximise the total profit.
        
        // take case of gold
        // you buy it when the price is lowest 
        // you sell it when price is highest 
        // given that you can make as many transactions as possible 
        
        // now how to code it?
        // find the minimum price to buy till now
        // find the maximum price to sell till now 
        
        int n = prices.size()-1;
        int buy=0;
        int sell=0;
        int cur=0;
        int total_profit=0;
        
        while(cur<n)
        {
            // finding lowest price till now
            // descending order k baad wala loweest price dhundo
            while(cur<n and (prices[cur]>=prices[cur+1]))
                cur++;
            buy = prices[cur];
            
            // sell at maximum price
            // ascending order k baad wala highest price dhundo
            while(cur<n and (prices[cur]<=prices[cur+1]))
                cur++;
            sell = prices[cur];
            
            total_profit+= sell-buy;
        }
        return total_profit;
        
        
        
        
        
        
        
    }
};