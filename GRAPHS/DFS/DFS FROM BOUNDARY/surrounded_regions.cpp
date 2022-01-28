class Solution {
public:
    
    // VARIETY : DFS FROM BOUNDAY 
    // apply dfs from cells which have O on ots border, will remove that connected component which is invalid 
    // then mark the remaining cells of the board which are unvisited , as X
    
       
    bool vis[1005][1005];
    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, 1, -1};
    
    void dfs(int i, int j, int n, int m , vector<vector<char>>&board)
    {
        vis[i][j]=1;
        
        for(int k=0;k<4;k++)
        {
            int xx = i+dx[k];
            int yy = j+dy[k];
            
            if(xx>=0 and yy>=0 and xx<n and yy<m and vis[xx][yy]==0 and board[xx][yy]=='O')
            {
                    dfs(xx, yy, n, m, board);        
            }
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        memset(vis, 0, sizeof(vis));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    // if we are any of the border position
                    if(board[i][j]=='O' and vis[i][j]==0)
                    dfs(i, j, n, m, board);
                }
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 and board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
        
    }
};