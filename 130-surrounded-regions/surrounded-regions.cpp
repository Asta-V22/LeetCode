class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(board.empty()) return;
        int cols = board[0].size();

        vector<vector<char>> vis(rows, vector<char>(cols,'X'));

        queue<pair<int,int>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if((i==0 || j==0|| i==rows-1 || j==cols-1) && board[i][j]=='O'){
                    vis[i][j] = 'O';
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto cat = q.front();
            q.pop();

            int row = cat.first;
            int col = cat.second;

            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};

            for(int i=0; i<4; i++){
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols && board[newRow][newCol]=='O' && vis[newRow][newCol]=='X'){
                    vis[newRow][newCol] = 'O';
                    q.push({newRow,newCol});
                }
            }
        }

        //vis contains our desired 
        for(int i=0 ;i<rows; i++){
            for(int j=0; j<cols; j++){
                board[i][j] = vis[i][j];
            }
        }

    }   
};