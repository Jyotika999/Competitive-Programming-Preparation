class Solution {
public:
    
    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, 1, -1};
    
    int dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vis)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j]==1 || grid[i][j]==0)
            return 0;
        int temp=1;
        vis[i][j]=1;
        
        for(int k=0;k<4;k++)
        {
            int xx = i + dx[k];
            int yy = j + dy[k];
            if(xx>=0 and yy>=0 and xx<grid.size() and yy<grid[0].size() and vis[xx][yy]==0 and grid[xx][yy]==1)
            {
                
                
                temp+= dfs(xx, yy, grid, vis);
            }
            
        }
        return temp;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int maxcnt=0;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    maxcnt = max(maxcnt, dfs(i, j, grid, vis));
                }
            }
        }
        
        return maxcnt;
    }
};