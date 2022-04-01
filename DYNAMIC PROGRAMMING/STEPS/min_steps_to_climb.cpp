class Solution {
public:
    
    int dp[1005];
    
    int solve(int i, vector<int>&cost)
    {
        if(i<0)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        if(i==0)
        {
            return dp[i]=cost[0];
        }
        
        return dp[i]=min(cost[i]+ solve(i-1,cost),  cost[i]+solve(i-2, cost));
         
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        memset(dp, -1, sizeof(dp));
        
        int n = cost.size();
        
        return min(solve(n-1, cost), solve(n-2, cost));
        
        
    }
};