class Solution {
public:
    string removeOuterParentheses(string s) {
    
        int n = s.length();
        
        string temp="";
        string ans = "";
        stack<char>ds;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(ds.empty())
                {
                    // continue;
                }
                else
                {
                    temp+=s[i];
                }
                ds.push(s[i]);
            }
            else
            {
                if(ds.top()=='(')
                    ds.pop();
                
                if(ds.empty())
                {
                    ans+=temp;
                    temp="";
                }
                else
                    temp+=s[i];
                
            }
        }
        
        return ans;
        
    }
    
};


// ( ( ) ( ) ) ( ( ) )