class Solution {
private:
    void bfs(vector<vector<char>>& grid, int rowSrc, int colSrc, int row, int col){
        queue<pair<int,int>> q;
        q.push({rowSrc,colSrc});
        grid[rowSrc][colSrc] = '2';
        //now we have the source node in our queue


    while(!q.empty()){
        auto [curRow, curCol] = q.front();
        q.pop();

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i=0; i<4; i++){
            int newRow = curRow + dr[i];
            int newCol = curCol + dc[i];
            if(newRow>=0 && newRow<row && newCol>=0 && newCol<col && grid[newRow][newCol]=='1'){
                grid[newRow][newCol]='2';    //marked visited
                q.push({newRow, newCol});
            }
        }
    }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        

        int row = grid.size();
        int col = grid[0].size();



        int count = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                
                //if it is 1 then it means we have not done bfs here yet
                if(grid[i][j]=='1'){
                    count++;
                    bfs(grid, i,j, row, col);
                } 
            }
        }

        return count;
    }
};