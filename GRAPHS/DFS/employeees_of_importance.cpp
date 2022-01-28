/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    vector<int>graph[2005];
    int sum=0;
    int vis[2005];
    map<int,int>mp;
    
    void dfs(int node)
    {
        vis[node]=1;
         sum+=mp[node];
        
        for(auto child : graph[node])
        {
            if(!vis[child])
            {
                // cout<<child.first<<" "<<child.second<<"\n";
               
                dfs(child);
            }
        }
    }
    
    int getImportance(vector<Employee*> emp, int id) {
        
        int n = emp.size();
        memset(vis, 0, sizeof(vis));
        
        for(int i=0;i<n;i++)
        {
            int id = emp[i]->id;
            int imp = emp[i]->importance;
            vector<int>sub =  emp[i]->subordinates;
            int nsub=sub.size();
            mp[id]=imp;
            
            for(int j=0;j<nsub;j++)
            {
            graph[id].push_back(sub[j]);
                // directed hai , coz subordinates ki baat hori, so take care
            // graph[sub[j]].push_back(id);
            }   
        }
        
        dfs(id);
        return sum;
    }
};