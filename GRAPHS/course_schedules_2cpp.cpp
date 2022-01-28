class Solution {
public:
    
    vector<int>graph[100005];
    int indegree[100005];
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>ans;
        memset(indegree, 0, sizeof(indegree));
        for(int i=0;i<pre.size();i++)
        {
            int u = pre[i][0];
            int v = pre[i][1];
            
            graph[v].push_back(u);
            indegree[u]++;
            
        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(auto child : graph[cur])
            {
                indegree[child]--;
                if(indegree[child]==0)
                {
                    q.push(child);
                }
            }
        }
        vector<int>temp;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]!=0)
                return temp;
        }
        
      return ans;
        
        
    }
};