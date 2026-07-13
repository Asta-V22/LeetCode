class Solution {

private:
    void dfs(int sr, int sc, vector<vector<int>> &ans, vector<vector<int>> &image, int startColor, int row, int col, int color){
        ans[sr][sc] = color;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        //checking in all 4 directions
        for(int i=0; i<4; i++){
            int newRow = sr+dr[i];
            int newCol = sc+dc[i];

            if(newRow>=0 && newRow<row && newCol>=0 && newCol<col && image[newRow][newCol] == startColor && ans[newRow][newCol] != color ){
                dfs(newRow,newCol,ans,image,startColor, row, col, color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int row = image.size();
        int col = image[0].size();



        dfs(sr, sc, ans, image, startColor, row,col, color);

        return ans;
        
    }
};