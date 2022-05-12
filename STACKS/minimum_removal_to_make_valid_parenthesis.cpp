class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.length();
        int pre[n+5];
        
        memset(pre, 0, sizeof(pre));
        for(int i=n-1;i>=0;i--)
        {
            if(i!=n-1)
                pre[i]+=pre[i+1];
            
            if(s[i]==')')
                pre[i]++;
        }
        
        
        string ans="";
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(pre[i]>=cnt+1)
                {
                    ans+=s[i];
                    cnt++;
                }
                else
                {
                    continue;
                }
            }
            else if(s[i]==')')
            {
                if(cnt>0)
                {
                    cnt--;
                    ans+=s[i];
                }
                else
                    continue;
            }
            else if(s[i]>='a' and s[i]<='z')
            {
                ans+=s[i];   
            }
        }
        
        return ans;
        
        
        
        
    }
};