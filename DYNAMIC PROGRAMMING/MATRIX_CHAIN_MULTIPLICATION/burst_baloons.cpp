class Solution {
public:
    int dp[305][305];
    
    int solve(int i, int j, vector<int>&nums)
    {
        if(i>j)
            return 0;
        
        if(i==j)
        {
            int ans = nums[i];
            if(i-1>=0)
            ans*= nums[i-1];
            if(i+1<nums.size())
            ans*= nums[i+1];
            
            return dp[i][j]=ans;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int res=0;
        
        for(int k=i;k<=j;k++)
        {
            int temp1 = solve(i, k-1, nums);
            int temp2 = solve(k+1, j, nums);
            
            int cur = nums[k];
            // if we burst kth balloon , i-1 wala left adjacent hoga 
            if(i-1>=0)
            {
                cur*= nums[i-1];
            }
            // if we burst kth balooon, j+1 wala right adjacent hoga 
            if(j+1<nums.size())
            {
                cur*= nums[j+1];
            }
            res = max(res, (temp1 + temp2 + cur ));
        }
       return dp[i][j]=res; 
        
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=n-1;
        memset(dp, -1, sizeof(dp));
        
       return solve(i, j, nums);
        
    }
};