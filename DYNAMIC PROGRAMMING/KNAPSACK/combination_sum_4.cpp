class Solution {
public:
    
    
    
    int combinationSum4(vector<int>& nums, int target) {
    
        int n = nums.size();
        vector<unsigned long long int>dp(target+1, 0);
        
        sort(nums.begin(), nums.end());
        
        dp[0]=1;
        for(unsigned long long int i=1;i<=target;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums[j]<=i)
                {
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        
        return dp[target];
        
        
        
    }
};