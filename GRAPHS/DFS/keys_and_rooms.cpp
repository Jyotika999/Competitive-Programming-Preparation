class Solution {
public:
    
    void dfs(int node, vector<vector<int>>&rooms, bool vis[])
    {
        vis[node]=1;
        
        for(auto child : rooms[node])
        {
            if(!vis[child])
            {
                dfs(child, rooms, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        
        // since initially only room 0 is unlocked
        dfs(0, rooms, vis);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                return false;
            }
        }
        
        return true;
    }
};



// rooms[]= [[1],[2],[3],[]]
// room 0 --> key 1 --> room 1 unlock --> key 2 --> room 2 unlock --> key 3 --> room 3 unlock
// n rooms = 0, 1, 2, 3 
// all rooms unlocked
// hence true
    

// rooms[]= [[1,3],[3,0,1],[2],[0]]

// room 0 --> key 1, key 3
// room 1 --> key 0, key 1, key 3
// room 3 --> key 0 
// but room 2 , is still unvisited , since its key is also placed within the same room

// hence, false 

// since , some kind of edges are getting formed
// and traversal is getting started from its parent room , from where they got the key to open the current room.
// rooms[i] depicting the edge between it and other room numbers whose keys are present in rooms[i]
