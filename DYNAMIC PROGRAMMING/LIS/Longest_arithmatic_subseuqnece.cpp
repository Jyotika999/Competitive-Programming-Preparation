int solve(vector<int>& nums) {
    
    int n = nums.size();
    if(n==0)
    return 0;

    // int dp[1005][1005];
    // for(int i=0;i<1005;i++)
    // {
    //     for(int j=0;j<1005;j++)
    //     dp[i][j]=1;
    // }
    vector<map<int,int>>dp(1005);
   // vector<vector<int>>dp(n, vector<int>)
    int maxi=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int dif = nums[j]-nums[i];
            dp[j][dif]= max(dp[j][dif], dp[i][dif]+1);

            maxi = max(maxi, dp[j][dif]);

        }
    }
    return maxi+1;
}