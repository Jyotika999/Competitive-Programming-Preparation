class Solution {
public:
    
    
    int solve( int last, int n)
    {
        if(n==0)
        {
            // ans.push_back(s);
            
           
            return 1;
        }
        
       
        
        int ans=0;
        if(last==0)
            last=1;
        for(int i=last;i<=5;i++)
        {
           ans+= solve(i, n-1);
        }
        return ans;
    }
    
    int countVowelStrings(int n) {
        
        // vector<char>v;
        // v.push_back('a');
        // v.push_back('e');
        // v.push_back('i');
        // v.push_back('o');
        // v.push_back('u');
        
        
        // vector<string>ans;
        
        return solve(0, n);
        // return ans.size();
        
    }
};