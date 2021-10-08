class Solution {
public:
    int maximumDifference(vector<int>& nums) {
     
        int ans = -1;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                {
                    int dif = nums[i] - nums[j];
                    ans = max(ans, dif);
                }
            }
        }
        
        
        return ans;
        
        
    }
};