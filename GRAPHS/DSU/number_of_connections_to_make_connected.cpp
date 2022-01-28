https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    vector<int>graph[100005];
    
    // vector<int>parent(100005);
    // vector<int>rank(100005);
    int parent[100005];
    int r[100005];
    
    void unionn(int a, int b)
    {
        a = find_parent(a);
        b = find_parent(b);
        
        if(a!=b)
        {
            if(r[a]<r[b])
            {
                parent[a]=b;
            }
            else if(r[a]>r[b])
            {
                parent[b]=a;
            }
            else
            {
                parent[a]=b;
                r[b]++;
            }
        }
    }
    int find_parent(int i)
    {
        if(i==parent[i])
            return i;
        return parent[i]=find_parent(parent[i]);
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        
        int edges = con.size();
        int extra_cables=0;
        
        for(int i=1;i<=n;i++)
        {
            r[i]=0;
            parent[i]=i;
        }
        
        for(int i=0;i<edges;i++)
        {
            int u = con[i][0];
            int v = con[i][1];
            
            if(find_parent(u)!=find_parent(v))
            {
                unionn(u, v);
            }
            else
            {
                extra_cables++;
            }
            
            // graph[u].push_back(v);
            // graph[v].push_back(u);
        }
        
        int connected_component=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            {
                connected_component++;
            }
        }
        
        connected_component--;
        cout<<connected_component<<" "<<extra_cables<<"\n";
        if(extra_cables< connected_component)
            return -1;
        else
            return connected_component;
    
        
    
    }
};



// this means that , at the end the number of connected componennts = 1
// this means we need to make use of those redundant edges/ wires , to connect it to other componnets which are not in same component
// for a connected componnet , with n nodes, the  number of edges required to make the whole component as connected will be n-1 edges


