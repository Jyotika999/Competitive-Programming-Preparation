class Solution {
public:
    
    
    // for checking validity
    // check if row is valid
    // check if column is valid
    // check if current subgrid of size 3*3 is valid
    
    
    bool valid(int i, int j, int val , vector<vector<char>>&board)
    {
        for(int k=0;k<9;k++)
        {
            if(board[i][k]==val)
                return false;
        }
        
        for(int k=0;k<9;k++)
        {
            if(board[k][j]==val)
                return false;
        }
        
        int xx = i/3 * 3;
        int yy = j/3 * 3;
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                if(board[xx+x][yy+y]==val)
                    return false;
            }
        }
        return true;
        
    }
    bool solve(int i, int j, vector<vector<char>>&board)
    {
        // all rows are traversed
        if(i==board.size())
            return true;
        
        // i and j for current cell 
        // x and y for making next call 
        int x = i;
        int y = j;
        // you are at last column of current row, 
        // therefore you need to move to next row now
        if(j==board[0].size()-1)
        {
            x=i+1;
            y=0;
        }
        else
        {
            y=j+1;
            x=i;
        }
        
        if(board[i][j]!='.')
        {
           return solve(x, y, board);
        }
        else
        {
            for(int k=1;k<=9;k++)
            {
                if(valid(i, j, k+'0', board))
                {
                    board[i][j]=k+'0';
                    if(solve(x, y, board))
                        return true;
                    board[i][j]='.';
                }
            }
        }
        
        return false;
        
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        
        // either start from 1st row and travel till last row 
        // or start from 1st column and then travel till last column 
        
        // here i am starting from first row 
        // if i reach the last row's last column that is nth position , 
        // then i will return 
        
        solve(0, 0, board);
        // return board;
        
        
    }
};