class Solution {
public:
    
      

    
    vector<int> diffWaysToCompute(string exp) {
    
        
         vector<int>ans;
        int n  = exp.length();
     
       
        // checking for ()*() , all possible operators ke about brackets lgayenge 
        // aur further woh ek sub bracket ko solve krke sare possible ans dega 
        // ese hee second sub bracket ko solve krke sare possible ans milenge 
        // bus ab dono ko combine krdenge depending upon current operator is +, -, or * 
        for(int i=0;i<exp.length();i++)
        {
            if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*')
            {
                vector<int> ans1 =  diffWaysToCompute(exp.substr(0, i));
                vector<int> ans2 =  diffWaysToCompute(exp.substr(i+1, n));
             
                  for(auto x : ans1)
                    {
                        for(auto y : ans2)
                        {
                            if(exp[i]=='+')
                            {
                                ans.push_back(x+y);
                            }
                            if(exp[i]=='-')
                            {
                                ans.push_back(x-y);
                            }
                            if(exp[i]=='*')
                            {
                                ans.push_back(x*y);
                            }
                        }
                    }
            }
        }
        
        // no operator , hence we need to return only the operand but in integer format 
        if(ans.size()==0)
        {
            ans.push_back(stoi(exp));
        }
             return ans;
    }
            
            
          
   
       
        
    };
