class Solution {
public:
    bool isValid(string s) {
        
        stack<char>container;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='('||s[i]=='{' || s[i]=='[')
                container.push(s[i]);
            else
            {
                if(!container.empty())
                {
                    if(s[i]==')' and container.top()=='(')
                        container.pop();
                    else if(s[i]=='}' and container.top()=='{')
                        container.pop();
                    else if(s[i]==']' and container.top()=='[')
                        container.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        
        return container.empty();
        
        
    }
};