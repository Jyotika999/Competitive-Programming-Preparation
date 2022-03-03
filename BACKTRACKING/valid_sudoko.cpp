class Solution {
public:
    
    bool valid(int i, int j, vector<vector<char>>&board, char val)
    {
        for(int x=0;x<9;x++)
        {
            if(board[x][j]==val and x!=i)
            {
                return false;
            }
        }
        for(int x=0;x<9;x++)
        {
            if(board[i][x]==val and x!=j)
            {
                return false;
            }
        }
        
        int xx = i/3 * 3;
        int yy = j/3 * 3;
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                int curx = xx + x;
                int cury = yy + y;
                if(curx!=i and cury!=j and board[curx][cury]==val)
                    return false;
            }
        }
        
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {  if(valid(i, j, board, board[i][j]))
                    continue;
                   else 
                    return false;
                }
            }
        }
        return true;
        
        
    }
};