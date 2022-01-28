class Solution {
public:
    
    
    // those cells which are land cells, and these cells which are on boundary , any connected component , which have atleast 1 cell on the boundary of the grid, will be accesible cells
    
    // hence marking above cells as viisted 
    // marking the remaining cells as univisited
    
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    void dfs(int i, int j, int n, int m, vector<vector<int>>&grid)
    {
        grid[i][j]=0;
        
        for(int k=0;k<4;k++)
        {
            int xx = i + dx[k];
            int yy = j + dy[k];
            
            if(xx>=0 and yy>=0 and xx<n and yy<m and grid[xx][yy]==1)
            {
                dfs(xx, yy, n, m, grid);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1||j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        dfs(i, j, n, m, grid);
                    }
                    
                }
            }
        }
        
        int ct=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ct+=grid[i][j];
            }
        }
        return ct;
        
        
    }
};