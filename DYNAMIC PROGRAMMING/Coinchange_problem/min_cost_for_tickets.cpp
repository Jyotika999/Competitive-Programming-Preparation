class Solution {
public:
    
    int dp[366];
    
    int mini(int a, int b, int c)
    {
        return min(a, min(b,c));
        
    }
    
    int solve(vector<int>&costs, map<int,int>&mp, int day)
    {
        if(day>365)
            return 0;
        
        if(dp[day]!=-1)
            return dp[day];
        
        if(mp[day]!=0)
        return dp[day] = mini(costs[0]+solve(costs, mp, day+1), 
                   costs[1]+solve(costs, mp, day+7), 
                   costs[2]+solve(costs, mp, day+30));
        else
        return dp[day]=solve(costs, mp, day+1);
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        map<int, int>mp;
        int d = days.size();
        
        for(int i=0;i<d;i++)
        {
            mp[days[i]]++;
        }
        
        memset(dp, -1, sizeof(dp));
        // 3 choices 
        // minimise the total cost 
        // if currrent day is there to travel , then travel 
        // else dont travel and move to the next day 
        
        return solve( costs,  mp , 1);
        
        
    }
};