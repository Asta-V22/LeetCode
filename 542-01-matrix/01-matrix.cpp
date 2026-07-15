class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols= mat[0].size();

        vector<vector<int>> vis(rows, vector<int>(cols));
        vector<vector<int>> dist(rows, vector<int>(cols));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            auto cat = q.front();
            q.pop();

            int row = cat.first.first;
            int col = cat.first.second;

            int distance = cat.second;

            dist[row][col] = distance;

            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};

            for(int i=0; i<4; i++){
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols && !vis[newRow][newCol]){
                    vis[newRow][newCol] = 1;
                    q.push({{newRow,newCol},distance+1});
                }
            }
         }

    return dist;

    }
};