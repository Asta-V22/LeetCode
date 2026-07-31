class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        //for transpose first we have to swap the values in a simple traversal and then reverse individual rows

        //but but but the above only works if the matrix is gurantted to be a square matrix

        //for variable m and n we need a new matrix, also need to swap the rows and cols
        vector<vector<int>> newmat(cols, vector<int>(rows));

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                newmat[j][i] = matrix[i][j];
            }
        }

        return newmat;
    }
};