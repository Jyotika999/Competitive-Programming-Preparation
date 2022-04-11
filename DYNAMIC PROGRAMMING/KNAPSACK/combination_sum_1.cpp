class Solution {
public:
    
     void solve(vector<vector<int>>&ans, vector<int>&c, vector<int>temp, int target, int i , int n)
     {
         
         if(target==0)
         {
             ans.push_back(temp);
             return;
         }
         if(i>=n)
             return;
         
         if(c[i]<=target)
         {
             // either choose or not choose 
             // choosing it , but we could again repeat it
             temp.push_back(c[i]);
             solve(ans, c, temp, target-c[i], i, n);
             temp.pop_back();
             
             solve(ans, c, temp, target, i+1, n);
         }
         else
         {
             solve(ans, c, temp, target, i+1, n);
         }
         
     }
    
    vector<vector<int>> combinationSum(vector<int>& c,  int target) {
    
       vector<vector<int>>ans;
    
        int n = c.size();
        vector<int>temp;
        solve(ans, c, temp, target, 0, n);
        return ans;
        
    }
};