class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxs(9);

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    //check if this number has came before in the same row
                    if(rows[i].count(board[i][j])) return false;
                    rows[i].insert(board[i][j]);

                    //check if this number has came before in the same cols
                    if(cols[j].count(board[i][j])) return false;
                    cols[j].insert(board[i][j]);

                    //check if this number has came anywhere in the box before
                    int numBox = (i/3)*3 + (j/3);

                    if(boxs[numBox].count(board[i][j])) return false;
                    boxs[numBox].insert(board[i][j]);
                }
            }
        }

        return true;

    }
};