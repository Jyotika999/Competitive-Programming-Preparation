class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.length();
        stack<int>ds;
        int len=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                ds.push(i);
            }
            else
            {
                if(!ds.empty())
                {
                    int prev = ds.top();
                    if(s[prev]=='(')
                    {
                        ds.pop();
                        len = max(len, i-prev+1);
                    }
                    else
                    {
                        ds.push(i);
                    }
                }
                else
                {
                    ds.push(i);
                }
            }
        }
        
        int prev=n;
        
        if(ds.empty())
        {
            len = max(len, n);
        }
       
        
        while(!ds.empty())
        {
            int cur = ds.top();
            cout<<cur<<" "<<prev<<"\n";
            len = max(len, prev-cur-1);
            ds.pop();
            prev=cur;
        }
        len = max(len, prev);
        
        return len;
    }
};