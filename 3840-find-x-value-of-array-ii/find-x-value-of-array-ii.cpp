class Solution {
private:
    struct Node {
        int total_prod;
        int prefix_cnt[5];

        Node() {
            total_prod = 1;
            fill(prefix_cnt, prefix_cnt + 5, 0);
        }
    };

    class SegmentTree {
    private:
        int n;
        int k;
        vector<Node> tree;

        Node merge(const Node& L, const Node& R) {
            Node res;
            res.total_prod = (L.total_prod * R.total_prod) % k;
            
            // Include prefix counts from the Left child
            for (int r = 0; r < k; ++r) {
                res.prefix_cnt[r] = L.prefix_cnt[r];
            }
            
            // Combine full Left child with prefixes from the Right child
            for (int r = 0; r < k; ++r) {
                if (R.prefix_cnt[r] > 0) {
                    int combined_rem = (L.total_prod * r) % k;
                    res.prefix_cnt[combined_rem] += R.prefix_cnt[r];
                }
            }
            return res;
        }

        Node make_leaf(int val) {
            Node res;
            int rem = val % k;
            res.total_prod = rem;
            res.prefix_cnt[rem] = 1;
            return res;
        }

        void build(const vector<int>& nums, int node, int l, int r) {
            if (l == r) {
                tree[node] = make_leaf(nums[l]);
                return;
            }
            int mid = l + (r - l) / 2;
            build(nums, 2 * node, l, mid);
            build(nums, 2 * node + 1, mid + 1, r);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }

        void update(int node, int l, int r, int idx, int val) {
            if (l == r) {
                tree[node] = make_leaf(val);
                return;
            }
            int mid = l + (r - l) / 2;
            if (idx <= mid) {
                update(2 * node, l, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, r, idx, val);
            }
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }

        Node query(int node, int l, int r, int ql, int qr) {
            if (ql <= l && r <= qr) {
                return tree[node];
            }
            int mid = l + (r - l) / 2;
            if (qr <= mid) {
                return query(2 * node, l, mid, ql, qr);
            }
            if (ql > mid) {
                return query(2 * node + 1, mid + 1, r, ql, qr);
            }
            return merge(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
        }

    public:
        SegmentTree(const vector<int>& nums, int mod) : k(mod) {
            n = nums.size();
            tree.resize(4 * n);
            build(nums, 1, 0, n - 1);
        }

        void update(int idx, int val) {
            update(1, 0, n - 1, idx, val);
        }

        Node query(int start_idx) {
            return query(1, 0, n - 1, start_idx, n - 1);
        }
    };

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        SegmentTree st(nums, k);
        vector<int> result;
        result.reserve(queries.size());

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int target_x = q[3];

            st.update(index, value);
            Node resNode = st.query(start);
            result.push_back(resNode.prefix_cnt[target_x]);
        }

        return result;
    }
};