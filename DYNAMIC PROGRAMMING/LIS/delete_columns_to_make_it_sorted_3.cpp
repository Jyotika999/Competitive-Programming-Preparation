class Solution {
public:
    
    bool valid(vector<string>&strs, int i, int j)
    {
        int n  = strs.size();
        for(int k=0;k<n;k++)
        {
            if(strs[k][i] >=strs[k][j])
                continue;
            else
                return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        
        // if we keep a track of which all columns should not be deleted , then total columns - totall kept will be the required number of columns to be deleted 
        
        // hence if we want to keep the ith column and jth column
        // then check that all the characters in rows of ith col and jth col also follow lexiographicity , else you need to delete the currennt character 
        
        int n = strs.size();
        int m = strs[0].size();
        vector<int>dp(m+1, 1);
        int maxi = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(valid(strs, i, j))
                {
                    dp[i]= max(dp[i], dp[j]+1);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        for(int i=0;i<m;i++)
            cout<<dp[i]<<" \n";
        return (m-maxi);
        
    }
};