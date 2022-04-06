class Solution {
public:
   
    bool canJump(vector<int>& nums) {
        
         
        int n = nums.size();
        int maxdis = 0;
        
        for(int i=0;i<n;i++)
        {
            
            int curdis = nums[i]+i;
            // if(nums[i]!=0)
            if(maxdis < i)
                break;
            maxdis = max(maxdis, curdis);
        }
        
        return (maxdis>=n-1);
    }
};