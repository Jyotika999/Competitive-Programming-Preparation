class Solution {
public:
    
    int dp[1005];
    
    int solve(int start, int end, vector<int>&nums)
    {
        if(start>end)
            return 0;
        
        if(dp[start]!=-1)
            return dp[start];
        
        return dp[start] = max(solve(start+1, end, nums), solve(start+2, end, nums)+nums[start]);
        
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        memset(dp, -1, sizeof(dp));
        
        int choose_first = solve(0, n-2, nums);
        memset(dp, -1, sizeof(dp));
        
        int choose_second = solve(1, n-1, nums);
        
        return max( choose_first,  choose_second);
    }
};