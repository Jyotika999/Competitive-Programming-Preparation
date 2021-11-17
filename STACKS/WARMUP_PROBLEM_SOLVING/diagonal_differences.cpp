
// Problem: Diagonal Difference
// Contest: HackerRank - Algorithms - Warmup
// URL: https://www.hackerrank.com/challenges/diagonal-difference/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


int diagonalDifference(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();
    
    int left=0;
    int right=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==j)
            {
                left+= arr[i][j];
            }
            if(i+j == m-1)
            {
                right+= arr[i][j];
            }
        }
    }

return abs(left-right);



}