class Solution {
public:
    vector<vector<int>>allpaths;
    int vis[100];
    
    void dfs(int node, vector<int>temp, int target, vector<vector<int>>&graph)
    {
           // temp.push_back(node);
        // vis[node]=1;
        if(node==target)
        {
            allpaths.push_back(temp);
            return;
        }
     
        
        for(auto child : graph[node])
        {
            // if(vis[child]==0)
            {
                temp.push_back(child);
                dfs(child, temp, target, graph);
                temp.pop_back();
            }
        }
        temp.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        memset(vis, 0, sizeof(vis));
        
        vector<int>temp;
        temp.push_back(0);
        dfs(0, temp, graph.size()-1, graph);
        return allpaths;
        
    }
};