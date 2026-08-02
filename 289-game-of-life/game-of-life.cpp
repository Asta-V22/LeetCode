class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int count = 0;
                for(int k=0; k<8; k++){
                    int newRow = i+dr[k];
                    int newCol = j+dc[k];
                    

                    if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols && (board[newRow][newCol]==3 || board[newRow][newCol]==1)) count++;

                }
                if(board[i][j]==1 && count<2){
                    board[i][j]=3;             //alive to dead
                }
                else if(board[i][j]==0 && count==3){
                    board[i][j]=4;       //dead to alive
                }
                else if(count>3 && board[i][j]==1){
                    board[i][j] = 3;
                }
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j]==3) board[i][j]=0;
                if(board[i][j]==4) board[i][j]=1;
            }
        }
    }
};