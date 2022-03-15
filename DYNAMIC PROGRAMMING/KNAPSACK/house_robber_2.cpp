// TIME : O(N)
// SPACE : O(N)

// SINCE EITHER OF HOUSE 1 OR HOUSE 2 CAN BE ROBBED BUT NOT TOGETHER BECAUSE 
// CHOICE 1 : HOUSE 1 INCLUDE, HOUSE N EXCLUDE, PROBLEM REDUCED TO CHECCK CHOICES OF HOUSE 1 TO HOUSE N-1
// CHOICE 2 : HOUSE N INCLUDE, HOUSE 1 EXCLUDE, PROBLEM REDUCED TO CHECCK CHOICES OF HOUSE 2 TO HOUSE N

class Solution {
public:
    
    int solve(vector<int>nums, int ind, int n, int dp[])
    {
        if(ind>n)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int include = nums[ind]+solve(nums, ind+2, n, dp);
        int exclude = solve(nums, ind+1, n, dp);
            
        return dp[ind] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
            return nums[0];
        
        int dp1[n];
        int dp2[n];
        
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        
        int choice1 = solve(nums, 0, n-2, dp1);
        int choice2 = solve(nums, 1, n-1, dp2);
        
        return max(choice1, choice2);
        
        
    }
};