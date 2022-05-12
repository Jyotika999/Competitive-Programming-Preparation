class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char>ds;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            if(ds.empty())
                ds.push(s[i]);
            else
            {
                if(ds.top()==s[i])
                    ds.pop();
                else
                    ds.push(s[i]);
            }
        }
        string final_string = "";
        
        while(!ds.empty())
        {
            final_string+= ds.top();
            ds.pop();
        }
        reverse(final_string.begin(), final_string.end());
        return final_string;
        
        
        
        
    }
};