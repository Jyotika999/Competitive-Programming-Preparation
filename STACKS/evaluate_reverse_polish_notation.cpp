class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>s;
        
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                int ff = s.top();
                s.pop();
                int ss = s.top();
                s.pop();
                s.push(ff+ss);
            }
            else if(tokens[i]=="-")
            {
                int ff = s.top();
                s.pop();
                int ss = s.top();
                s.pop();
                s.push(-ff+ss);
            }
            else if(tokens[i]=="*")
            {
                int ff = s.top();
                s.pop();
                int ss = s.top();
                s.pop();
                s.push(ff*ss);
            }
            else if(tokens[i]=="/")
            {
                int ff = s.top();
                s.pop();
                int ss = s.top();
                s.pop();
                s.push(ss/ff);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
            cout<<s.top()<<" \n";
        }
        
        return s.top();
        
    }
};