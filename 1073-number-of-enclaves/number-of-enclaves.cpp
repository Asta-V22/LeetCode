class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(i==0||j==0||i==rows-1||j==cols-1){
                    if(grid[i][j]==1){
                        grid[i][j]=2;    //marked 2 as visited
                        q.push({i,j});

                    }
                }
            }
        }

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();



            for(int i=0; i<4; i++){
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols && grid[newRow][newCol] == 1){
                    q.push({newRow,newCol});
                    grid[newRow][newCol] = 2;
                }
            }
        }

        int count =0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1) count++;
            }
        }

        return count;


    }
};