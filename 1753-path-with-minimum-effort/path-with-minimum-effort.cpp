class Solution {
public:
    typedef tuple<int,int,int> t;
    vector<vector<int>> directions{{0,1},{1,0},{-1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> res(rows, vector<int>(cols,INT_MAX));

        priority_queue<t, vector<t>, greater<t>> pq;

        res[0][0]= 0;  //max effort from src to src is 0
        pq.push({0,0,0});

        while(!pq.empty()){
            auto [d,i,j] = pq.top();
            pq.pop();

            for(auto dir : directions){
                int x = i + dir[0];
                int y = j + dir[1];
                if(x>=0 && x<rows && y>=0 && y<cols){
                    int d_ = abs(heights[i][j]-heights[x][y]);
                    d_ = max(d_,d);
                    if(res[x][y]>d_){
                        res[x][y] = d_;
                        pq.push({d_,x,y});
                    }
                }
            }
        }

        return res[rows-1][cols-1];
    }
};