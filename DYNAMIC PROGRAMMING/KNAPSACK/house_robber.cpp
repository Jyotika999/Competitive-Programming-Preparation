class Solution {
public:
    
    int dp[1005];
    int solve(vector<int>&nums, int ind, int n)
    {
        if(ind>=n)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        // include
        int include = nums[ind] + solve(nums, ind+2, n);
        // exclude
        int exclude = solve(nums, ind+1, n);
        
        return dp[ind]= max(include, exclude);
        
        
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        memset(dp, -1, sizeof(dp));
        
        solve(nums, 0 , n);
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
           maxi  = max(maxi, dp[i]);
        }
        return maxi;
        
    }
};