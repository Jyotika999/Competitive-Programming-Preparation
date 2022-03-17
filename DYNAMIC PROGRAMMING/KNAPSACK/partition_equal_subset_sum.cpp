class Solution {
public:
    
    
    bool solve(vector<int>&nums, int ind, int sum , vector<vector<int>>&dp)
    {
        if(sum==0)
            return true;
        
        if(ind>=nums.size())
            return false;
        
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        
        if(nums[ind]<=sum)
        {
            return dp[ind][sum] = solve(nums, ind+1, sum-nums[ind], dp) || solve(nums, ind+1, sum, dp);
        }
        else
        {
            return dp[ind][sum] = solve(nums, ind+1, sum, dp);
        }
        
            
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
        }
        
        if(sum%2!=0)
            return false;
        
        vector<vector<int>>dp(n+5, vector<int>(sum+5, -1));
        return solve(nums, 0, sum/2, dp);
        
    }
};