class Solution {
public:
    
    int dp[605][105][105];
    int num_zero(string s)
    {
        int ct=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
                ct++;
        }
        return ct;
    }
    int num_one(string s)
    {
        int ct=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
                ct++;
        }
        return ct;
    }
    
    
    int solve(vector<pair<int,int>>&v, int m, int n, int ind, int sz)
    {
        if(ind>=sz||m<0 || n<0)
            return 0;
        
      
        
        if(dp[ind][m][n]!=-1)
            return dp[ind][m][n];
        
        int include=0;
        int exclude=0;
        if(v[ind].first<=m and v[ind].second<=n)
        {
            // either choose or not choose
            include = max(1 + solve(v, m-v[ind].first, n-v[ind].second, ind+1, sz) , solve(v, m, n, ind+1, sz))     ;
            // return dp[ind]=include;
        }
        else
        {
        exclude = solve(v, m, n, ind+1, sz);
            // return dp[ind]=exclude;
        }
        return dp[ind][m][n] = max(include, exclude);
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        memset(dp, -1, sizeof(dp));
        
        vector<pair<int,int>>v;
        for(int i=0;i<sz;i++)
        {
            string cur = strs[i];
            int zero = num_zero(cur);
            int one = num_one(cur);
            // cout<<cur<<" "<<zero<<" "<<one<<"\n";
            v.push_back({zero, one});
        }
        
        return solve(v, m, n, 0, sz);
        // int maxi=0;
        // for(int i=0;i<sz;i++)
        // {
        //     cout<<dp[i]<<"\n";
        //     maxi = max(maxi, dp[i]);
        // }
        // return maxi;
    }
};