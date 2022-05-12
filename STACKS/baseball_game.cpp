class Solution {
public:
    int calPoints(vector<string>& ops) {
   
        int sum=0;
        stack<int>scoreboard;
        
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="+")
            {
                int ff = scoreboard.top();
                scoreboard.pop();
                int ss = scoreboard.top();
                // scoreboard.pop();
                
                // scoreboard.push(ss);
                scoreboard.push(ff);
                cout<<"\n + wala ";
                cout<<ff<<" "<<ss<<" "<<ff+ss<<"\n";
                scoreboard.push(ff+ss);
            }
            else if(ops[i]=="C")
            {
                scoreboard.pop();
            }
            else if(ops[i]=="D")
            {
                scoreboard.push(scoreboard.top()*2);
            }
            else
            {
               scoreboard.push(stoi(ops[i])); 
            }
            if(!scoreboard.empty())
            cout<<scoreboard.top()<<" ";
        }
        
        while(!scoreboard.empty())
        {
            sum+= scoreboard.top();
            scoreboard.pop();
        }
        return sum;
        
    }
};