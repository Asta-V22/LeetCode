class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));

        dp[0][0][grid[0][0]] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){              //as we have already processed it earlier
                    continue;
                }

                bitset<1024> up;
                bitset<1024> down;

                if(i>0){
                    up = dp[i-1][j];
                }

                if(j>0){
                    down = dp[i][j-1];
                }

                bitset<1024> combo = up | down;

                //now we need to iterate in this final combo and do xor with the bitset present in the grid[i][j]

                for(int k = 0; k<1024; k++){
                    if(combo[k]){   //if it is set then do the xor with it
                        int newxor = k ^ grid[i][j];
                        dp[i][j][newxor] = 1;   //storing for further turns
                    }
                }
            }
        }

        //now the [m-1][n-1] contains the bitset with all possible xor values we'll just extract the initial set one


        for(int i=0; i<1024; i++){
            if(dp[m-1][n-1][i]){
                return i;
            }
        }

        return 0;
    }
};