class Solution {
public:
    int scoreOfParentheses(string s) {
        
        
        
        stack<string>ds;
        
        s="("+s+")";
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                ds.push("(");
            else
            {
                if(ds.top()=="(")
                {
                    ds.pop();
                    ds.push("1");
                }
                else
                {
                    int sum=0;
                    while(!ds.empty() and ds.top()!="(")
                    {
                        sum+=stoi(ds.top());
                        ds.pop();
                    }
                    ds.pop();
                    ds.push(to_string(sum*2));
                }
            }
        }
        
        
    
        
        
        return stoi(ds.top())/2;
        
    }
};