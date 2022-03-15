class Solution {
public:
    
    // unordered_map<vector<int>, int>mp;
    
    void generate(vector<int>&nums, int n, unordered_map<int,int>&freq, vector<int>cur, vector<vector<int>>&ans, map<vector<int>,int>&mp)
    {
        if(freq.size()==n)
        {
            if(mp[cur]==0)
            {
                ans.push_back(cur);
                mp[cur]++;
                return;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(freq[i]==0)
            {
                freq[i]=1;
                cur.push_back(nums[i]);
                generate(nums, n, freq, cur, ans, mp);
                cur.pop_back();
                freq.erase(i);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int>freq;
        vector<int>cur;
        vector<vector<int>>ans;
       map<vector<int>, int>mp;
        
        generate(nums, n, freq, cur, ans, mp);
        return ans;
    }
};