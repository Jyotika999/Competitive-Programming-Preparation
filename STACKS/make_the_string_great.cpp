class Solution {
public:
    string makeGood(string s) {
       
        int n = s.length();
        stack<char>ds;
        
        for(int i=0;i<n;i++)
        {
            if(ds.empty())
                ds.push(s[i]);
            else
            {
                if(isupper(s[i]) and islower(ds.top()) and ((s[i]-'A')==(ds.top()-'a')))
                    ds.pop();
                else if(islower(s[i]) and isupper(ds.top()) and ((s[i]-'a')==(ds.top()-'A')))
                    ds.pop();
                else
                    ds.push(s[i]);
            }
        }
        
        string ans="";
        while(!ds.empty())
        {
            ans= ds.top()+ ans;
            ds.pop();
        }
        return ans;
        
        
    }
};