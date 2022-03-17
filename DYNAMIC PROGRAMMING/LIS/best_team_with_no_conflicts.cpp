class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        vector<pair<int,int>>v;
        int n = scores.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({ages[i], scores[i]});
        }
        
        sort(v.begin(), v.end(), greater<>());
        
        int dp[n];
        memset(dp, -1, sizeof(dp));
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            dp[i]=v[i].second;
            for(int j=0;j<i;j++)
            {
                if(v[j].second >= v[i].second)
                {
                    dp[i] = max(dp[i] , dp[j]+ v[i].second);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
        
        
    }
};