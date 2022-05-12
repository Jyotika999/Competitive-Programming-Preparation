class Solution {
public:
    
    
    int solve( int last, int n, vector<vector<int>>&dp)
    {
        if(n==0)
        {
            // ans.push_back(s);
            
           
            return dp[last][n]= 1;
        }
          
        
        if(dp[last][n]!=-1)
            return dp[last][n];
       
        
        int ans=0;
        if(last==0)
            last=1;
        for(int i=last;i<=5;i++)
        {
           ans+= solve(i, n-1, dp);
        }
        return dp[last][n]= ans;
    }
    
    int countVowelStrings(int n) {
        
        // vector<char>v;
        // v.push_back('a');
        // v.push_back('e');
        // v.push_back('i');
        // v.push_back('o');
        // v.push_back('u');
        
        
        // vector<string>ans;
        vector<vector<int>>dp(10, vector<int>(n+5, -1));
        return solve(0, n, dp);
        // return ans.size();
        
    }
};