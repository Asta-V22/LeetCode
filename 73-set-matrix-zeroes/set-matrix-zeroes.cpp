class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> trackrows(m);
        vector<int> trackcols(n);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    trackrows[i] = 1;
                    trackcols[j]= 1;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(trackrows[i] == 1 || trackcols[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};