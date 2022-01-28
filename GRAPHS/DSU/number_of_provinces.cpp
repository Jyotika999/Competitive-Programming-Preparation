class Solution {
public:
    int parent[205];
    int sz[205];
    
    int find_parent(int i)
    {
        if(parent[i]==i)
            return i;
        
        return parent[i]=find_parent(parent[i]);
    }
    void unionn(int i,int j)
    {
        i = find_parent(i);
        j = find_parent(j);
        
        if(i!=j)
        {
            if(sz[i]<sz[j])
            {
                sz[j]+=sz[i];
                parent[i]=j;
            }
            else
            {
                sz[i]+=sz[j];
                parent[j]=i;
            }
        }
    }
    int findCircleNum(vector<vector<int>>&grid) {
        
        int n = grid.size();
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            sz[i]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    unionn(i, j);
                }
            }
        }
        
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            {
                ct++;
            }
        }
        return ct;
    }
};