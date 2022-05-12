class Solution {
public:
    
    void solve(vector<vector<int>>&ans, vector<int>temp, int k, int n, map<int,int>mp)
    {
        if(n==0)
        {
            // sort(temp.begin(), temp.end());
            if(temp.size()==k)
            ans.push_back(temp);
            return;
            
        }
        
        int start=1;
        if(!temp.empty())
            start= temp.back();
        for(int i=start;i<=9;i++)
        {
            if(mp[i]==0 and i<=n)
            {
                temp.push_back(i);
                mp[i]=1;
                solve(ans, temp, k, n-i, mp);
                temp.pop_back();
                mp[i]=0;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        map<int,int>mp;
        solve(ans, temp, k, n, mp);
        return ans;
    }
};