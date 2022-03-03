class Solution {
public:
    
    // min heap used for creating a  graph
    // because i want lexicographicaaly smalles possible strings 
    
    // question is basically about visiting alll edges
    
    unordered_map<string, priority_queue<string, vector<string> , greater<string>>>graph;
    
    void dfs(string node, vector<string>&result)
    {
        while(!graph[node].empty())
        {
            auto cur = graph[node].top();
            graph[node].pop();  // erasing it beacuse visited the edge once 
            dfs(cur, result);
        }
        result.push_back(node);
    }
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        int n = tickets.size();
        
        for(int i=0;i<n;i++)
        {
            string u = tickets[i][0];
            string v = tickets[i][1];
            graph[u].push(v);
        }
        
        vector<string>result;
        dfs("JFK" , result);
        reverse(result.begin(), result.end());
        return result;
        
        
        
        
        
    }
};