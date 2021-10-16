class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>>s;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            int cur = nums[i];
            int low=i+1;
            int high=n-1;
            int val = 0 - cur;
            
            while(low<high)
            {
                if(nums[low]+nums[high]==val)
                {
                    s.insert({cur, nums[low], nums[high]});
                    low++;
                    high--;
                }
                else if(nums[low]+ nums[high]<val)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        
        
        vector<vector<int>>ans (s.begin(), s.end());
        return ans;
    }
};