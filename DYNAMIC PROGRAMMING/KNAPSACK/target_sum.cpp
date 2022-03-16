class Solution {
public:
    
    int countways(int sum, vector<int>&nums, int ind, int n, map<pair<int,int>, int>&dp)
    {
//         if(n==0)
//             return 0;
        
        // this base condiition is very important 
        if(sum==0 and ind==n)
            return dp[{sum, ind}]=1;
        
        if(ind>=n)
            return 0;
        
        if(dp[{sum, ind}]!=-1)
            return dp[{sum,ind}];
        
        if(nums[ind]<=sum)
        {
            return dp[{sum, ind}] = (countways(sum-nums[ind], nums, ind+1, n, dp) +countways(sum, nums, ind+1, n, dp));
        }
        else
        {
            return dp[{sum, ind}]= countways(sum, nums, ind+1, n, dp);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int totalsum = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            totalsum+= nums[i];
        }
        if(totalsum < target)
            return 0;
        
        
       
        map<pair<int,int>, int>dp;
        
        for(int i=0;i<=totalsum;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[{i,j}]=-1;
            }
        }
        // vector<vector<int>>dp(totalsum+5, vector<int>(n+5, -1));
        int sum1 = (totalsum + target);
        if(sum1%2!=0)
            return 0;
        sum1/=2;
        return countways(sum1, nums, 0, n, dp);
    }
};