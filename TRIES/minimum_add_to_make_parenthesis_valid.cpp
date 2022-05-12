class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char>ds;
        int n = s.length();
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                ds.push(s[i]);
            else
            {
                if(!ds.empty())
                {
                    if(ds.top()=='(')
                        ds.pop();
                    else
                        ct++;
                }
                else
                    ct++;
            }
        }
        
        while(!ds.empty())
        {ct++;
            ds.pop();}
        return ct;
    }
};