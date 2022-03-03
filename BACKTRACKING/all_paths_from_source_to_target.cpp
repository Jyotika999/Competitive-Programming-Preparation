class Solution {
public:
    
    
    void dfs(int src, int target, vector<int>&cur_path, vector<vector<int>>&all_paths, vector<vector<int>>&graph)
    {
        if(src==target)
        {
          
            all_paths.push_back(cur_path);
            return;
        }
        for(auto child : graph[src])
        {
            // include current child
            cur_path.push_back(child);
            // check if path exists
            dfs(child, target, cur_path, all_paths, graph);
            // exclude the current child
            cur_path.pop_back();
            
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int>cur_path;
        vector<vector<int>>all_paths;
        int n = graph.size();
        cur_path.push_back(0);
        dfs(0, n-1, cur_path, all_paths, graph);
        
        return all_paths;
        
        
    }
};