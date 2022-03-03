class Solution {
public:
    
    map<pair<int,int>, int>mp;
    map<int,int>vis;
    vector<int>graph[100005];
    int ct=0;
    void dfs(int node)
    {
        vis[node]=1;
        for(auto child : graph[node])
        {
           
            if(!vis[child])
            {
                if(mp[{child, node}])
                {
                   // already forward edge exists , you need not reverse
                }
                else
                {
                    // a reverse edge exists, now you need to reverse 
                    ct++;
                }
                dfs(child);
                
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& con) {
        
   // if i treat the graph as undirected
  // if i apply dfs in this graph from node 0 
        // then i check that if the edge is in forward direction, ie edge exists between i and 0 , then no need to reverse else yes 
        
        int c = con.size();
        for(int i=0;i<c;i++)
        {
            int  u  = con[i][0];
            int  v  = con[i][1];
            
            // taking care of directed edge
            mp[{u,v}]++; 
           
            
            // creating an undirected graph 
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        //applying dfs from 0 node, 
        dfs(0);
        return ct;
        
        
    }
};