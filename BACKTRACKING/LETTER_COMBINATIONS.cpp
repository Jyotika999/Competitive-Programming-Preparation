class Solution {
public:
    
    map<char, string>mp;
   
    void solve(string digits, int ind,  string res, vector<string>&ans)
    {
    
        if(ind==digits.length())
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=0;i<mp[digits[ind]].size();i++)
        {
            res.push_back(mp[digits[ind]][i]);
            solve(digits, ind+1, res, ans);
            res.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
       
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
    
        int n = digits.size();
        
        vector<string>ans;
        if(n==0)
            return ans;
        solve(digits, 0,  "", ans); // parameters:  string, corresponding index of string ,index in map , currently formed resultant string, answer vector
       
        return ans;
        
    }
};