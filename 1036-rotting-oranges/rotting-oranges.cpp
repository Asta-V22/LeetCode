class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }    

        int currTime =0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int currRow = p.first.first;
            int currCol = p.first.second;

            currTime = p.second;

            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};

            

            for(int i=0; i<4; i++){
                int newRow = currRow + dr[i];
                int newCol = currCol+ dc[i];

                if(newRow>=0&& newCol >=0 && newRow <rows && newCol<cols && grid[newRow][newCol]==1){
                    grid[newRow][newCol] = 2;
                    q.push({{newRow,newCol},currTime+1});
                }


            }   
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return currTime;
    }
};