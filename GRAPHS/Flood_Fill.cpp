class Solution {
public:
    
    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, 1, -1};
    
    
    void dfs(vector<vector<int>>&image, int r, int c, int nc, int old)
    {
        image[r][c]=nc;
        
        for(int k=0;k<4;k++)
        {
            int xx = r + dx[k];
            int yy = c + dy[k];
            if(xx>=0 and yy>=0 and xx<image.size() and yy<image[0].size() and image[xx][yy]==old)
            {
                dfs(image, xx, yy, nc, old);
            }
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(image[sr][sc] != newColor)
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
        
        
        
    }
};