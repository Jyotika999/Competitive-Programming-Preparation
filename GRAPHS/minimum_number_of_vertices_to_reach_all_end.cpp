class Solution {
public:
    
    vector<int>graph[100005];
    
    void dfs(int node, int vis[])
    {
        vis[node]=1;
        for(auto child : graph[node])
        {
            if(vis[child]==0)
            {
                dfs(child, vis);
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int>vertices;
        vector<int>order;
        
        int e = edges.size();
        int vis[n];
        int indegree[n];
        memset(vis, 0, sizeof(vis));
        memset(indegree, 0, sizeof(indegree));
        queue<int>q;
        
        for(int i=0;i<e;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        
        // finding the topological sorting order of the graph 
        // to find the exact order of the order in which the nodes must be visited 
        // to visit the whole graph
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            order.push_back(cur);
            for(auto child : graph[cur])
            {
                indegree[child]--;
                if(indegree[child]==0)
                {
                    q.push(child);
                }
            }
        }
        for(int i=0;i<order.size();i++)
        {
            if(vis[order[i]]==0)
            {
                dfs(order[i], vis);
                vertices.push_back(order[i]);
            }
        }
        
       return vertices;
        
        
        
    }
};