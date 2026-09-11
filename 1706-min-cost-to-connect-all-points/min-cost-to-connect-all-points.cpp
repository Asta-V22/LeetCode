class Solution {
public:
    typedef pair<int, pair<int,int>> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        //let's create an adj that will show the connection with all the edges
        vector<vector<pair<int,int>>> adj(n);  //{v,wt}
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                auto x = points[i];
                auto y = points[j];

                int xi = x[0];
                int yi = x[1];
                int xj = y[0];
                int yj = y[1];

                int wt = abs(xi-xj)+abs(yi-yj);

                adj[i].push_back({j,wt});
            }
            
        }

        //now we have successfully transformed our adj and can apply prims normally

        priority_queue<p, vector<p>, greater<p>> pq;    //--->{wt,{v,u}}
        vector<int> vis(n);

        pq.push({0,{0,-1}});
        int total = 0;

        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();

            int wt = x.first;
            int v = x.second.first;
            int u = x.second.second;

            if(vis[v]) continue;

            vis[v] = 1;
            total+=wt;

            //add the connecting edges in the pq
            for(auto &x: adj[v]){
                int dest = x.first;
                int dist = x.second;

                pq.push({dist,{dest,v}});
            }

        }
        return total;


    }
};