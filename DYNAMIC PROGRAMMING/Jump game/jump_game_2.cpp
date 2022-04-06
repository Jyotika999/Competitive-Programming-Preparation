class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int ct=1;
        
        if(n==1)
            return 0;
        int maxindex = nums[0];
        int maxreach = nums[0];
        
        for(int i=1;i<n;i++)
        {
            int temp = i+nums[i];
            maxreach = max(maxreach, temp);
            
            if(maxindex==i and i!=n-1)
            {
                maxindex = max(maxindex, maxreach);
                ct++;
            }
           
        }
        
        return ct;    
    }
};