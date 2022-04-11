class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
          
        int dp[n+5][amount+5];
        memset(dp, 0, sizeof(dp));
        
        //    n==1 wali row mein divisibility check krke fill krni h 
        
        for(int i=1;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                dp[1][i] = i/coins[0];
            }
            else
            {
                dp[1][i] = INT_MAX - 1;
            }
        }
        
        
               
//         sum=0 wali row mein INT_MAX -1 se fill krenege 

        for(int i=0;i<=amount;i++)
        {
            dp[0][i] = INT_MAX-1;
        }
        
        
         //      
//         fill rest of the rows accordingly 
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
                }
                else
                {
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        
        if(dp[n][amount]!=INT_MAX-1)
        return dp[n][amount];
        else
            return -1;
        
    }
};