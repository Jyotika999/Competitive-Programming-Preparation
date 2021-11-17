// 
// Spreadsheets often use this alphabetical encoding for its columns: "A", "B", "C", ..., "AA", "AB", "AC", ..., "ZZ", "AAA", "AAB", "AAC", ....
// 
// Given a string s representing an alphabetical column id, return its column number. For example, given "A", return 1. Given "AA", return 27.
// 
int solve(string s) {
    
    int n = s.length();
    if(n==1)
    {
        return s[0]-'A'+1;
    }
    else
    {
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans= ans*26 + (s[i]-'A'+1);
        }
        // n--;
        // ans = 26*n+s[n-1]-'A'+1;
        return ans;
    }

}