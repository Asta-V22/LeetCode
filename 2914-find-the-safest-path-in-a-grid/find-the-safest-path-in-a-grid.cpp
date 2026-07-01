class Solution {
public:
    int n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // Checks whether we can reach the destination
    // using only cells having safeness >= limit
    bool canReach(vector<vector<int>>& dist, int limit) {

        if (dist[0][0] < limit)
            return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()){

            auto [r,c] = q.front();
            q.pop();

            if(r == n-1 && c == n-1)
                return true;

            for(int k=0;k<4;k++){

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr<0 || nr>=n || nc<0 || nc>=n)
                    continue;

                if(vis[nr][nc])
                    continue;

                if(dist[nr][nc] < limit)
                    continue;

                vis[nr][nc] = true;
                q.push({nr,nc});
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        // Step 1: Multi-source BFS
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 1){

                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){

            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr<0 || nr>=n || nc<0 || nc>=n)
                    continue;

                if(dist[nr][nc] != -1)
                    continue;

                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr,nc});
            }
        }

        // Step 2: Binary Search
        int low = 0;
        int high = 2 * n;   // maximum possible Manhattan distance
        int ans = 0;

        while(low <= high){

            int mid = low + (high-low)/2;

            if(canReach(dist, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

   
};