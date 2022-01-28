class Solution {
public:
    
    vector<pair<int,int>>graph[105];
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        k++;
        int fs = flights.size();
        
        for(int i=0;i<fs;i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            
            // directed graph 
            graph[u].push_back({v, w});
        }
        
        priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        
        // dis, k, src
        pq.push({0, 0, src});
        vector<int>dis(n+1, INT_MAX);
        vector<int>stops(n+1, INT_MAX);
        
        stops[src]=0;
        dis[src]=0;
        
        
        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            int curdis = get<0>(cur);
            int curnode = get<2>(cur);
            int curstops = get<1>(cur);
            
            
            if(curstops>k)
                continue;
            
            // if(dis[curnode] < curdis)
                // continue;
            
            
            // cout<<curnode<<" "<<curdis<<" "<<curk<<"\n";
            
            
            if(curnode==dst)
                return curdis;
            
            
            for(auto c : graph[curnode])
            {
                int child = c.first;
                int wt = c.second;
                int nextstop = curstops+1;
               if(dis[child] > wt + curdis)
                {
                    dis[child] = wt+ curdis;
                    stops[child] = nextstop;
                    pq.push({dis[child],  nextstop, child});
                }
                else if(curstops < stops[child])
                {
                    stops[child] = nextstop;
                    dis[child] = wt + curdis;
                    pq.push({dis[child] , stops[child] , child});
                }
            }
            
            
        }
        
        for(int i=0;i<n;i++)
            cout<<i<<" "<<dis[i]<<"\n";
        
       // if(dis[dst]==INT_MAX)
            return -1;
        //lse
           // return dis[dst];
        
        
        
    }
};