class Solution {
public:
     
    bool valid(int i, int j, int n, vector<string>&board)
    {
        // no clash from same row
        for(int row=0;row<n;row++)
        {
            if(board[row][j]=='Q')
                return false;
        }
        
        // no clash from same column
        for(int col=0;col<n;col++)
        {
            if(board[i][col]=='Q')
                return false;
        }
        
        int row=i;
        int col=j;
        // no clash from left diagonal
        while(row>=0 and col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        
        // no clash from right diagonal
        row=i;
        col=j;
        while(col<n and row>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col++;
        }
        
        return true;
    }
    void solve(vector<vector<string>>&ans, vector<string>&board, int i, int n)
    {
        if(i>=n)
        {
            ans.push_back(board);
            return ;    
        }
        
        for(int j=0;j<n;j++)
        {
            if(board[i][j]=='.')
            {
                if(valid(i, j, n, board))
                {
                    board[i][j]='Q';
                    solve(ans, board, i+1, n);
                    board[i][j]='.';
                }
            }
        }
        
    }
    int totalNQueens(int n) {
        vector<string>board;
        string s="";
        for(int i=0;i<n;i++)
        {
            s+=".";
        }
        for(int i=0;i<n;i++)
        {
            board.push_back(s);
        }
        
        vector<vector<string>>ans;
        
        solve(ans, board, 0, n);
        
        return ans.size();
        
    }
};

