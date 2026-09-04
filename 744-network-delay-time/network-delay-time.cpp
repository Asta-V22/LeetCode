class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //first let's create the adjacency list first
        vector<vector<pair<int,int>>> adj(n+1);  //1 based indexing

        for(auto &x: times){
            adj[x[0]].push_back({x[1],x[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> res(n+1,INT_MAX);

        res[k] = 0;  //origin of the signal
        pq.push({0,k});

        while(!pq.empty()){
            auto [dist,node] = pq.top();
            pq.pop();

            if(dist>res[node]) continue;

            //let's check where can we go from here
            for(auto &[v_node, v_dist]: adj[node]){
                if(dist + v_dist < res[v_node]){
                    res[v_node] = dist+v_dist;
                    pq.push({res[v_node],v_node});
                }
            }
        }

        //now our result array will be filled with the shortest time it will take to reach to that praticular node from source

        int min_time = INT_MIN;
        for(int i=1; i<=n; i++){
            if(res[i]==INT_MAX) return -1;
            min_time = max(min_time, res[i]);
        }

        return min_time;

    }
};