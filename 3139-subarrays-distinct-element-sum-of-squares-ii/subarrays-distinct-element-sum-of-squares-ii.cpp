class Solution {
     static const long long MOD = 1e9 + 7;
    vector<long long> tree, lazy;

    void push(int node, int l, int r) {
        if (lazy[node]) {
            int m = (l + r) / 2;
            apply(2*node, l, m, lazy[node]);
            apply(2*node+1, m+1, r, lazy[node]);
            lazy[node] = 0;
        }
    }
    void apply(int node, int l, int r, long long v) {
        tree[node] = (tree[node] + v * (r - l + 1)) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
    }
    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { apply(node, l, r, 1); return; }
        push(node, l, r);
        int m = (l + r) / 2;
        update(2*node, l, m, ql, qr);
        update(2*node+1, m+1, r, ql, qr);
        tree[node] = (tree[2*node] + tree[2*node+1]) % MOD;
    }
    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        push(node, l, r);
        int m = (l + r) / 2;
        return (query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr)) % MOD;
    }
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        unordered_map<int, int> last;      // value -> last index seen

        long long cur = 0, ans = 0;        // cur = sum of d[i]^2 for current j
        for (int j = 0; j < n; j++) {
            int p = last.count(nums[j]) ? last[nums[j]] : -1;
            long long s = query(1, 0, n - 1, p + 1, j);
            cur = (cur + 2 * s + (j - p)) % MOD;
            update(1, 0, n - 1, p + 1, j);
            ans = (ans + cur) % MOD;
            last[nums[j]] = j;
        }
        return ans;
    }
};