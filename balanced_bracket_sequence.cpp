bool solve(string s) {
    
    int n = s.length();
    stack<char>c;

    for(int i=0;i<n;i++)
    {
        
            if(s[i]=='{' || s[i]=='(' || s[i]=='[')
            c.push(s[i]);
    
        
        else
        {
            if(!c.empty())
            {
                if(s[i]==')')
                {
                    if(c.top()=='(')
                    c.pop();
                    else
                    return false;
                }
                else if(s[i]=='}')
                {
                    if(c.top()=='{')
                    c.pop();
                    else
                    return false;
                }
                else if(s[i]==']')
                {
                    if(c.top()=='[')
                    c.pop();
                    else
                    return false;
                }
                else{
                    return false;
                }
            }
            else
            return false;
        }
    }

    if(c.empty())
    return true;
    else 
    return false;
}