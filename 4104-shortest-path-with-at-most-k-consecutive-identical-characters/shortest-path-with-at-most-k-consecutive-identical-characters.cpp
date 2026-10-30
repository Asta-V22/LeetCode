class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
         vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        const long long INF = LLONG_MAX;
        // dist[node * (k+1) + c] = min cost to reach node with run length c
        vector<long long> dist((long long)n * (k + 1), INF);
        auto id = [&](int node, int c) { return (long long)node * (k + 1) + c; };

        using T = tuple<long long, int, int>;           // {cost, node, run}
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[id(0, 1)] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, c] = pq.top(); pq.pop();
            if (d > dist[id(u, c)]) continue;           // stale entry
            if (u == n - 1) return (int)d;              // first pop of target = optimal

            for (auto [v, w] : adj[u]) {
                int nc = (labels[v] == labels[u]) ? c + 1 : 1;
                if (nc > k) continue;                   // would break the constraint
                long long nd = d + w;
                if (nd < dist[id(v, nc)]) {
                    dist[id(v, nc)] = nd;
                    pq.push({nd, v, nc});
                }
            }
        }
        return -1;
    }
};