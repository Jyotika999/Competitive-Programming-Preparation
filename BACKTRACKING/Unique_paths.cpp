class Solution {
public:
    
    void solve(int i, int j, int m, int n, int &ct)
    {
        if(i<0 || j<0 || i>=m || j>=n)
            return;
        if(i==m-1 and j==n-1)
        {
            ct++;
            return;
        }
        
        solve(i+1, j, m, n, ct);
        solve(i, j+1, m, n, ct);
        
    }
    int uniquePaths(int m, int n) {
        
        
        int ct=0;
        solve(0, 0, m, n, ct);
        return ct;
        
        
    }
};