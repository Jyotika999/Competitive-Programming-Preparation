class Solution {
public:
    
    int dp[20005];
    
   int solve(map<int,int>&mp, int maxi)
   {
       if(maxi==0)
           return 0;
       
       if(maxi==1)
       {
           return mp[1];
       }
       
       if(dp[maxi]!=-1)
           return dp[maxi];
       
       return dp[maxi] = max(mp[maxi]*maxi + solve(mp, maxi-2) , solve(mp, maxi-1));
   }
    
    int deleteAndEarn(vector<int>& nums) {
        
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int,int>mp;
        int maxi=0;
        memset(dp, -1, sizeof(dp));
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            maxi = max(maxi, nums[i]);
        }
        
        return solve(mp, maxi);
        
    }
};