class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int maxlen=0;
        vector<int>dp(n+5, 1);
        int value=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((nums[i]%nums[j]==0)||(nums[j]%nums[i]==0))
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
                
            }
            if(maxlen <= dp[i])
            {
                maxlen = dp[i];
                value = i;
            }
        }
        
        vector<int>ans;
        ans.push_back(nums[value]);
        for(int j=value;j>=0;j--)
        {
            // cout<<dp[j]<<"\n";
            if((dp[j]==dp[value]-1)and(nums[value]%nums[j]==0))
            {
                ans.push_back(nums[j]);
                value=j;
            }
        }
        
        cout<<maxlen<<"\n";
        return ans;
        
    }
};