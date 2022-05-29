class Solution {
public:
    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, 1, -1};
    int trapRainWater(vector<vector<int>>& height) {

        int n = height.size();
        int m = height[0].size();
        
        // create a visited array so that processed walo ko repeat na kro , else infiinte loop will start 
        vector<vector<int>>vis(n, vector<int>(m, 0));
        // priority queue which will sort elements on basis of ki sabse weak bar length konsi hai, jhan se water overflow hoga
        
        // take care ki boundary elements do baar na add hojaye 
        // pair<int, pair<int,int>>
        priority_queue< pair<int, pair<int,int>>, vector< pair<int, pair<int,int>>>, greater< pair<int, pair<int,int>>>>pq;
        
        for(int i=0;i<m;i++)
        { pq.push({height[0][i], {0, i}});
          vis[0][i]=1;}
        
        for(int i=0;i<m;i++)
        {    pq.push({height[n-1][i] , {n-1, i}});
             vis[n-1][i]=1;}
        
        for(int i=1;i<n-1;i++)
        {   pq.push({height[i][0] , {i, 0}});
            vis[i][0]=1;}
        
        for(int i=1;i<n-1;i++)
        {    pq.push({height[i][m-1], {i, m-1}});
             vis[i][m-1]=1;}
        
        
        
        int water=0;
        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            int val = cur.first;
            int xx = cur.second.first;
            int yy = cur.second.second;
            
            for(int k=0;k<4;k++)
            {
                int x = xx+dx[k];
                int y = yy+dy[k];
                if(x>=0 and y>=0 and x<n and y<m and vis[x][y]==0)
                {
                    if(height[x][y]< height[xx][yy])
                    {
                        // x,y wale k upar pani store hojayega , this means uski height chage hojayegi ab 
                        water+= height[xx][yy]-height[x][y];
                        height[x][y] = height[xx][yy];
                        
                        // delegate again
                        pq.push({height[x][y] , {x, y}});
                        vis[x][y]=1;
                    }
                    else
                    {
                        // always delegate 
                        pq.push({height[x][y], {x, y}});
                        vis[x][y]=1;
                    }
                }
            }
            
        }
        
        
        return water;
        
        
    }
};


