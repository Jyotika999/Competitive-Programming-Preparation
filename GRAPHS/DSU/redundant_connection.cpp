class Solution {
public:
    
    
    int parent[1005];
    int rank[1005];
    // if there exists an edge between u and v , such that the representative of component to which u belongs is same as the representative of component to which v belongs, then u and v are belonging to same set , hence we will add them to redundant edges
    
    
    int find_parent(int n)
    {
        if(n==parent[n])
            return n;
        
        return parent[n]=find_parent(parent[n]);
    }
    
    void unionn(int a, int b)
    {
        a = find_parent(a);
        b = find_parent(b);
        
        if(a!=b)
        {
            if(rank[a]<rank[b])
            {
                parent[a]=b;
            }
            else if(rank[a]>rank[b])
            {
                parent[b]=a;
            }
            else
            {
                // only if we have equal ranks, change rank only then , since it means depth, and if we are uniting two components with same rank, then we are ultimately increasing the depth by 1 
                rank[a]++;
                parent[b]=a;
            }
        }
    }
    
    void make_set(int i)
    {
        rank[i]=0;
        parent[i]=i;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        for(int i=0;i<edges.size();i++)
        {
            make_set(i);
        }
        vector<int>ans;
        for(int i=0;i<edges.size();i++)
        {
            vector<int>temp;
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(find_parent(u)==find_parent(v))
            {
                temp.push_back(u);
                temp.push_back(v);
                ans=temp;
            }
            else
            {
                unionn(u, v);
            }
        }
        
        return ans;
    }
};