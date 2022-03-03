class Solution {
public:
    vector<int>graph[505];
     vector<int>ans;
    
    // returning the node with minimum quietness 
    int dfs(int node, vector<int>&quiet)
    {
        if(ans[node]!=-1)
            return ans[node];
        
        ans[node]=node;
        for(auto child : graph[node])
        {
             int subtree_val = dfs(child, quiet);
            
            if(quiet[ans[node]] > quiet[subtree_val])
            {
                ans[node]=subtree_val;
             
            }
            
        }
        return ans[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int r = richer.size();
        
        ans.resize(quiet.size(), -1);
        for(int i=0;i<r;i++)
        {
            int u = richer[i][0];
            int v = richer[i][1];
            
            //  money[u]  > money[v]
            // hence we will create edge   v->u , because we need to track only those nodes which have money greater than or euql to the current node value
            // hence i will create only a directed edge
            graph[v].push_back(u);
        }
       
        // dp on graphs
        // if something is pehle se calculated, toh direct return krdo
        // otherwise calculate for its children and check if it is having minimum quietness , then update 
        for(int i=0;i<quiet.size();i++)
        {
           
            ans[i]=dfs(i, quiet);
            
        }
        
        return ans;
    }
};