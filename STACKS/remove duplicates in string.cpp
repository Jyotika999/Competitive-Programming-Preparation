class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.length();
        // map<char, int>mp;
        stack<pair<char,int>>ds;
        
        for(int i=0;i<n;i++)
        {
            // mp[s[i]]++;
            
            if(ds.empty())
                ds.push({s[i], 1});
            else
            {
                if(ds.top().first==s[i])
                    ds.push({s[i], ds.top().second+1});
                else
                    ds.push({s[i], 1});
            }
               if(ds.top().second==k)
               {
                   while(!ds.empty() and ds.top().first == s[i])
                       ds.pop();
               }
        }
        
        string ans="";
        while(!ds.empty())
        {
            ans+= ds.top().first;
            ds.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};