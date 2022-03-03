class Solution {
public:
    
    void combine(vector<int>&nums, int ind, int n, vector<int>&temp, vector<vector<int>>&ans)
    {
        if(ind==n)
        {
            if(find(ans.begin(), ans.end(), temp)==ans.end())
            {
                ans.push_back(temp);
            }
            return;
        }
        
        
        // exclude current element
        combine(nums, ind+1, n, temp, ans);
        
        // include current element
        temp.push_back(nums[ind]);
        combine(nums, ind+1, n, temp, ans);
        temp.pop_back();
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        vector<int>temp;
        int n = nums.size();
        combine(nums, 0, n, temp, ans);
        return ans;
    }
};