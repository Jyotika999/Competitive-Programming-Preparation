class Solution {
public:
    
    int maxtime=0;
    vector<int>graph[100005];
    vector<int>vis;
    
    map<int,int>time;
    
    void dfs(int node, int cur)
    {
        vis[node] =1;
        maxtime = max(maxtime, cur);
        for(auto child : graph[node])
        {
            if(vis[child]==0)
            {
                dfs(child, cur+time[child]);
            }
        }
    }
    
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) {
        
        maxtime=0;
        vis.resize(n);
        // memset(vis, 0, sizeof(vis));
        for(int i=0;i<n;i++)
        {
            time[i]=informTime[i];
        }
        
        for(int i=0;i<n;i++)
        {
            int u = i;
            int v = manager[i];
            
            if(v!=-1)
            graph[v].push_back(u);
        }
        
        dfs(headId, time[headId]);
        
        return maxtime;
        
    }
};