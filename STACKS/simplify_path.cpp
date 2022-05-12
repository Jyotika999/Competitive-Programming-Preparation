class Solution {
public:
    string simplifyPath(string path) {
        
        int n = path.length();
        
        stack<string>container;
        
        string temp="";
        
        if(path[n-1]!='/')
        {
            path.push_back('/');
            n++;
        }
        for(int i=0;i<=n;i++)
        {
            if(path[i]=='/')
            {
                if(temp=="" or temp==".")
                {
                    // do nothing 
                }
                else if(temp=="..")
                {
                    if(!container.empty())
                    {
                        container.pop();
                    }
                }
                else
                {
                    container.push(temp);
                    
                }
                   temp=""; 
            }
            else
            {
                temp+=path[i];
            }
        }
        
        string ans = "";
        while(!container.empty())
        {
            ans= "/"+container.top()+ans;
            container.pop();
        }
        
        if(ans=="")
            ans="/";
        
        return ans;
        
        
    }
};