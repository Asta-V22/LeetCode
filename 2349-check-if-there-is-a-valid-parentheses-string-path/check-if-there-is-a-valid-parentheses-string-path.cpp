class Solution {
public:
    int m;
    int n;

    int t[101][101][201];
    bool solve(int i, int j, int count,vector<vector<char>>& grid){
        if(grid[i][j]=='('){
            count++;
        }
        else{
            count--;
        }
        if(count<0){
            return false;
        } 
        if(t[i][j][count]!=-1){
            return t[i][j][count];
        }
        if(i==m-1 && j==n-1 && count==0) return t[i][j][count] = true;

        //now we'll move right or down
        if(i+1<m){
            if(solve(i+1,j,count,grid)){
                return t[i][j][count] = true;
            }
        }
        if(j+1<n){
            if(solve(i,j+1,count,grid)){
                return t[i][j][count] = true;
            }
        }
        return t[i][j][count] = false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0]==')') return false;
        m = grid.size();
        n = grid[0].size();
        if((m+n-1)%2!=0) return false;

        memset(t,-1,sizeof(t));
        return solve(0,0,0,grid);
    }
};