class Solution {
public:
    
    int dp[105][105];
    
    int solve(vector<int>&values, int i, int j)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            int temp1 = solve(values, i, k);
            int temp2 = solve(values, k, j);
            res = min(res, temp1+temp2+ values[i]*values[j]*values[k]);
            
        }
        if(res==INT_MAX)
            return dp[i][j]=0;
        
        return dp[i][j]= res;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        
        int n = values.size();
        int i=0;
        int j=n-1;
        memset(dp, -1, sizeof(dp));
        
        return solve(values, i, j);
    }
};