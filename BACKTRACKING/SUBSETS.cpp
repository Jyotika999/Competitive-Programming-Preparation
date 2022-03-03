class Solution {
public:
    
    void combine(vector<int>&nums, int ind, vector<int>temp, vector<vector<int>>&ans, int n)
    {
       if(ind>=n)
       {
           ans.push_back(temp);
           return;
       }
        
        // include current element
        temp.push_back(nums[ind]);
        combine(nums, ind+1, temp, ans, n);
        temp.pop_back();
        
        
        // exclude current element
        combine(nums, ind+1, temp, ans, n);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        
        int ind=0;
        int n = nums.size();
        combine(nums, ind, temp, ans, n);
        return ans;
    }
};