class Solution {
public:
    vector<pair<int,int>>graph[1000];
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        
        int dis[n];
        for(int i=0;i<n;i++)
        {
            dis[i]= INT_MAX;
        }
        int x = edges.size();
        for(int i=0;i<x;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            u--;
            v--;
            int wt = edges[i][2];
            graph[u].push_back({v, wt});
        }
        
        priority_queue<pair<int,int>>pq;
        dis[k-1]=0;
        pq.push({ 0, k-1});
        
        
        while(!pq.empty())
        {
            int cur = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            for(auto c : graph[cur])
            {
                int child = c.first;
                int wt = c.second;
                
                if(d + wt < dis[child])
                {
                    dis[child]= d + wt;
                    pq.push({ dis[child] , child});
                }
            }
            
        }
        
        
        int max_time=0;
        for(int i=0;i<n;i++)
        {
            cout<<i<<" "<<dis[i]<<"\n";
            if(dis[i]==INT_MAX)
                return -1;
            max_time = max(max_time, dis[i]);
        }
        
        return max_time;
    }
};