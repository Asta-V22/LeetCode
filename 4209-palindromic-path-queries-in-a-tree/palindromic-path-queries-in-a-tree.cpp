//MARKED FOR REVISIT


class Solution {
    int n, LOG = 17;
    vector<int> bit;

    // Fenwick over XOR: point xor, prefix-xor query
    void pointXor(int i, int v) {
        for (++i; i <= n; i += i & -i) bit[i] ^= v;
    }
    int prefixXor(int i) {
        int r = 0;
        for (++i; i > 0; i -= i & -i) r ^= bit[i];
        return r;
    }
    void rangeXor(int l, int r, int v) {
        pointXor(l, v);
        if (r + 1 < n) pointXor(r + 1, v);
    }

public:
    vector<bool> palindromePath(int n_, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        n = n_;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // ---- Iterative DFS: parent, depth, Euler tour times ----
        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n), tout(n), idx(n, 0);
        int timer = 0;
        vector<int> st = {0};
        up[0][0] = 0;
        tin[0] = timer++;
        while (!st.empty()) {
            int u = st.back();
            if (idx[u] < (int)adj[u].size()) {
                int v = adj[u][idx[u]++];
                if (v == up[0][u] && u != 0) continue;   // skip parent
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                tin[v] = timer++;
                st.push_back(v);
            } else {
                tout[u] = timer - 1;   // last tin inside u's subtree
                st.pop_back();
            }
        }

        // ---- Binary lifting table ----
        for (int k = 1; k < LOG; k++)
            for (int v = 0; v < n; v++)
                up[k][v] = up[k - 1][up[k - 1][v]];

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int k = 0; k < LOG; k++)
                if (diff >> k & 1) a = up[k][a];
            if (a == b) return a;
            for (int k = LOG - 1; k >= 0; k--)
                if (up[k][a] != up[k][b]) { a = up[k][a]; b = up[k][b]; }
            return up[0][a];
        };

        // ---- Build Fenwick: each node XORs its char into its subtree ----
        bit.assign(n + 1, 0);
        for (int v = 0; v < n; v++)
            rangeXor(tin[v], tout[v], 1 << (s[v] - 'a'));

        auto P = [&](int x) { return prefixXor(tin[x]); };

        // ---- Process queries ----
        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;
            if (type == "update") {
                char c;
                ss >> c;
                int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                if (delta) rangeXor(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                int v;
                ss >> v;
                int L = lca(u, v);
                int mask = P(u) ^ P(v) ^ (1 << (s[L] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};