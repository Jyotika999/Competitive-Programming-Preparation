int solve(vector<int>& nums, int dif) {
    
    int dp[100005];
      int n = nums.size();
    for(int i=0;i<=n+2;i++)
    {
        dp[i]=1;

    }

    int maxval=1;
  
    unordered_map<int,int>mp;

    for(int i=0;i<n;i++)
    {
        if(mp[nums[i]-dif]!=0)
        {
            int j = mp[nums[i]-dif];
            j--;
            dp[i] = max(dp[i], dp[j]+1);
        }
        maxval = max(maxval, dp[i]);
        mp[nums[i]]=i+1;
    }

return maxval;


}