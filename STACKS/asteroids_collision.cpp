class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
     
        int n = ast.size();
        
        stack<int>ds;
        
        for(int i=0;i<n;i++)
        {
            if(ast[i]>0 || ds.empty())
                ds.push(ast[i]);
            else
            {
               
                
                while(!ds.empty() and ds.top()>0 and (ds.top()<abs(ast[i])))
                    ds.pop();
                
                if(!ds.empty() and ds.top()==abs(ast[i]))
                    ds.pop();
                
                else
                {
                    if(ds.empty()|| ds.top()<0)
                    ds.push(ast[i]);
                }
            }
        }
        
        vector<int>v;
        while(!ds.empty())
        {
            v.push_back(ds.top());
            ds.pop();
        }
        reverse(v.begin(), v.end());
        return v;
        
        
        
    }
};