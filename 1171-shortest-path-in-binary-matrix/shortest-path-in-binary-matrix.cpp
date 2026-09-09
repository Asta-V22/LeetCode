class Solution {
public:
    //this is Dijkstra approach, here result matrix is useless as we return as we hit n-1,n-1 so no need to store anything and save your O(N2) HAPPY!!!!
    typedef tuple<int, int,int> P;
    vector<vector<int>> directions{{1,0},{0,1},{1,1},{-1,0},{0,-1},{-1,-1}, {-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        // vector<vector<int>> result(n, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;

        // result[0][0]=0;  //the starting point
        pq.push({0,0,0});
        //mark the starting point as visited
        grid[0][0] = 1;

        while(!pq.empty()){
            auto [d, i,j] = pq.top();
            pq.pop();

            if(i==n-1 && j==n-1) return d+1;
            //now we'll go in all 8 directions to find where we can go
            for(auto &dir: directions){
                int x = i + dir[0];
                int y = j + dir[1];

                if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0){
                    pq.push({d+1,x,y});
                    grid[x][y]=1;
                    // result[x][y] = d+1;
                }
            }

        }

        return -1;

    }
};