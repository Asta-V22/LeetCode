class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        //this queue will contain the coordinates of the cells

        if(grid[0][0]!=0) return -1;

        q.push({0,0});
        grid[0][0]=1;

        int dr[] = {-1,  1,  0, 0, -1, -1,  1, 1};
        int dc[] = { 0,  0, -1, 1, -1,  1, -1, 1};

        int visited = 0;
        while(!q.empty()){
            
            int size = q.size(); //level
            for(int k=0; k<size; k++){
                auto [i,j] = q.front();
                q.pop();

                if(i==n-1 && j==n-1) return visited+1;

                for(int l=0; l<8; l++){
                    int i_ = i+dr[l];
                    int j_ = j+dc[l];

                    if(i_>=0 && i_<n && j_>=0 && j_<n && grid[i_][j_]==0){
                        q.push({i_,j_});
                        grid[i_][j_]=1;
                    }
                }

            }
            visited++;


        }

        return -1;
    }
};