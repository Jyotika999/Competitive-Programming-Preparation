class Solution {
public:
    
    bool dfs(int node, vector<int>graph[], vector<int>&color, vector<int>&vis, int c)
    {
        vis[node]=1;
        color[node]=c;
        
        bool ans=true;
        for(auto child : graph[node])
        {
            if(vis[child]==0)
            {
                ans = ans and dfs(child, graph, color, vis, c^1);
            }
            else
            {
                if(color[child]==c)
                    return false;
            }
        }
        return ans;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        int nd = dislikes.size();
        vector<int>graph[n+2];
        vector<int>color(n+2, -1);
        vector<int>vis(n+2, 0);
        
        // int md = dislikes[0].size();
        
        for(int i=0;i<nd;i++)
        {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            
           graph[u].push_back(v);
           graph[v].push_back(u);
            
        }
        
        bool ans =  true;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
               ans = ans and  dfs(i, graph, color, vis, 0);
            }
        }
        
        return ans;
    }
};


// either use bipartion dfs wala method
// some possible methods are
//  use GRAPH COLORING ALGORIHTM 
//  use DISjOINT SET UNION
// since its using some kind of only two connected components
// as if we are able to form only two connected components or not

