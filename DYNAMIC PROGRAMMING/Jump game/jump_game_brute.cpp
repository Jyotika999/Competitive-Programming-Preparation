class Solution {
public:
    
    // BRUTE FORCE APPROACH 
    // TIME : O(N^2)
    // SPACE : O(N)
    bool canJump(vector<int>& nums) {
        
         
        int n = nums.size();
        // vector<int>vis(n, 0);
        queue<int>q;
        q.push(0);
        
        while(!q.empty())
        {
            auto cur = q.front();
            if(cur==n-1)
                return true;
            q.pop();
            for(int child=cur; child<=min(n-1, nums[cur]+cur);child++)
            {
                q.push(child);   
            }
        }
        return false;
        
        
    }
};