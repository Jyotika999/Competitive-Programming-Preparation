class Solution {
public:
    int dp[1005];
    
    int solve(int i, vector<int>&nums)
    {
        if(i>=nums.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        return dp[i]=max(nums[i]+solve(i+2, nums), solve(i+1, nums));
    }
    int rob(vector<int>& nums) {
        
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        
        return solve(0, nums);
        
    }
};

// take care , why greedy wont work
// take the test case nums=[2, 1, 1, 2]
// here the max ans will be 4 , but if you choose greedily then it will be 3 
// hence greedy fails
// becoz its not compulsory for every other adjacent to choose
// you always have a choice 
// either to include current element 
// or exclude current element
// you have decision to make
// you have to maximise the totalcost 