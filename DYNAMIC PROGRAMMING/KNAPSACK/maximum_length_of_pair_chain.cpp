class Solution {
public:
    
    bool valid(int i, int j, vector<vector<int>>&pairs)
    {
        int a = pairs[j][0];
        int b = pairs[j][1];
        int c = pairs[i][0];
        int d = pairs[i][1];
        
        return b<c;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end());
        
        int n = pairs.size();
        
        vector<int>dp(n, 1);
        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(valid(i, j, pairs))
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
    }
};