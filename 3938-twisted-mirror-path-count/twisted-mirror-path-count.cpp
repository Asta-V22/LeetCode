class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        // R[i][j]: ways to enter (i,j) moving right; D[i][j]: moving down
        vector<vector<long long>> R(m, vector<long long>(n, 0)), D = R;
        R[0][0] = 1;  // start: total ways at (0,0) = 1

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                // enter moving right, from (i, j-1)
                if (j > 0) {
                    if (grid[i][j-1] == 0) R[i][j] = (R[i][j-1] + D[i][j-1]) % MOD;
                    else                   R[i][j] = D[i][j-1];   // mirror: down -> right
                }
                // enter moving down, from (i-1, j)
                if (i > 0) {
                    if (grid[i-1][j] == 0) D[i][j] = (R[i-1][j] + D[i-1][j]) % MOD;
                    else                   D[i][j] = R[i-1][j];   // mirror: right -> down
                }
            }
        }
        return (R[m-1][n-1] + D[m-1][n-1]) % MOD;
    }
};