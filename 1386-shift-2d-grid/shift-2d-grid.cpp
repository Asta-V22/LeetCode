class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int total = m*n;

        vector<vector<int>> duplicate(m,vector<int>(n));

        //let's loop throught the grid to calculate the newIndexes and put them in the grid

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int oldIndex = i*n + j;
                int newIndex = (oldIndex + k) % total;

                int newRow = newIndex/n;
                int newCol = newIndex%n;
                

                duplicate[newRow][newCol] = grid[i][j];
            }
        }

        return duplicate;
    }
};