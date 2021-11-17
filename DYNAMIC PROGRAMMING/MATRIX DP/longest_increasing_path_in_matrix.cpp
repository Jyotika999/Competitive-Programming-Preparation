int dp[505][505];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int max1(int a, int b, int c, int d)
{
    return max(max(a,b), max(c,d));
}

int path(int i, int j, int n, int m, vector<vector<int>>&matrix)
{
    if(i<0 || j<0 || i>=n || j>=m)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int maxi=0;
    for(int k=0;k<4;k++)
    {
        int xx = i + dx[k];
        int yy = j + dy[k];

        if(xx>=0 and xx<n and yy>=0 and yy<m and (matrix[i][j] < matrix[xx][yy]))
        {
            maxi = max(maxi, path(xx, yy, n, m, matrix));
        }
    }
return dp[i][j] = maxi+1;

  


}
int solve(vector<vector<int>>& matrix) {
    
    int n = matrix.size();
    int m = matrix[0].size();
    memset(dp, -1, sizeof(dp));
int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dp[i][j]==-1)
            {
              ans = max(ans,   path(i, j, n, m, matrix));
            }
        }
    }

return ans;
}