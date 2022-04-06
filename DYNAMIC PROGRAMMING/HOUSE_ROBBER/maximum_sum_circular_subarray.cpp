class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int maxsum = nums[0];
        int minsum = nums[0];
        int curmaxsum = 0;
        int curminsum = 0;
        int totalsum =0;
        
        
        for(int i=0;i<n;i++)
        {
            curmaxsum = max(nums[i], curmaxsum + nums[i]);
            curminsum = min(nums[i], curminsum + nums[i]);
            
            maxsum = max(maxsum, curmaxsum);
            minsum = min(minsum, curminsum);
            totalsum += nums[i];
        }
        
        if(maxsum>0)
        {
            return max(maxsum, (totalsum - minsum));
        }
        else
        {
            return (maxsum);
        }
        
    }
};