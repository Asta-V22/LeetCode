class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m*n;

        

        k = k%totalElements;   //this will give the shift number
        if(k==0) return grid;

        //lets make a duplicate matrix that will store the new values
        vector<vector<int>> duplicate(m, vector<int>(n));

        for(int x=0; x<k; x++){
            //shift by one place everytime
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(i==m-1 && j==n-1){
                        duplicate[0][0]=grid[i][j];
                    }
                    else if(j==n-1){
                        duplicate[i+1][0]= grid[i][j];
                    }
                    else{
                        duplicate[i][j+1]=grid[i][j];
                    }
                }
            }

            grid=duplicate;


        }

        return grid;


    }
};