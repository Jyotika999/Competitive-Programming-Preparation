class Solution {
public:
    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, 1, -1};
    void dfs(int i, int j, vector<vector<int>>&graph, int n)
    {
        if(i<0 || i>=n || j<0 || j>=n || graph[i][j]==1)
            return;
        
        graph[i][j]=1;
        cout<<i<<" "<<j<<"\n";
        for(int k=0;k<4;k++)
        {
            int xx  = i + dx[k];
            int yy  = j + dy[k];
            if(xx>=0 and yy<n and xx<n and yy>=0 and graph[xx][yy]==0)
                dfs(xx, yy, graph, n);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        
        // creating graph , by shifting the graph to (n*2)*(n*2) grid
        
        int n = grid.size();
        vector<vector<int>>graph(n*3, vector<int>(n*3, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    // cout<<i*2<<" "<<j*2+1<<"\n";
                    // cout<<i*2+1<<" "<<j*2<<"\n";
                    graph[i*3][j*3+2] =  graph[i*3+2][j*3] = graph[i*3+1][j*3+1]= 1;
                }
                else if(grid[i][j]=='\\')
                {
                    // cout<<i*2<<" "<<j*2<<"\n";
                    // cout<<i*2+1<<" "<<j*2+1<<"\n";
                    graph[i*3][j*3] = graph[i*3+1][j*3+1] = graph[i*3+2][j*3+2] = 1;
                    
                }
               
            }
        }
        
        int ct=0;
        for(int i=0;i<n*3;i++)
        {
            for(int j=0;j<n*3;j++)
            {
               if(graph[i][j]==0)
               {
                   dfs(i, j, graph, n*3);
                   ct++;
               }
                // ct += dfs(graph, i, j) ? 1 : 0;  
                // ct+= dfs(graph, i, j, n)? 1 : 0;
            }
        }
        return ct;
    }
};