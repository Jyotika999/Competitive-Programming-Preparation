class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        // nearest greater to right 
        
        int n = temp.size();
        stack<pair<int,int>>s;
        vector<int>ans(n, 0);
        
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
                ans[i]=0;
            else
            {
                while(!s.empty() and (s.top().first <= temp[i]))
                      s.pop();
                      
                if(!s.empty())
                      ans[i]=s.top().second-i;
            }
            s.push({temp[i], i});
            
        }
        
        return ans;
        
    }
};