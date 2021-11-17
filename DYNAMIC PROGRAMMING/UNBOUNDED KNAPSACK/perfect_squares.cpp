
    int dp[n+5];
   // memset(dp, 0, sizeof(dp));

   for(int i=0;i<=n;i++)
   dp[i] = INT_MAX;


    dp[0]=0;
    dp[1]=1;


    for(int i=2;i<=n;i++)
    {
        for(int j=1;j*j<=i;j++)
        {
            // if(dp[i-j*j])
            // {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            //}
        }
    }
    return dp[n];