class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;

        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) >> 1;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAXX = 50005;

        set<int> obs;
        obs.insert(0);
        obs.insert(MAXX);

        for (auto &q : queries) {
            if (q[0] == 1)
                obs.insert(q[1]);
        }

        SegmentTree seg(MAXX + 1);

        int prv = 0;
        for (int x : obs) {
            if (x == 0) continue;
            seg.update(x, x - prv);
            prv = x;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = obs.upper_bound(x);
                --it;

                int leftObstacle = *it;

                int bestGap = max(
                    seg.query(0, x),
                    x - leftObstacle
                );

                ans.push_back(bestGap >= sz);
            } 
            else {
                int x = q[1];

                auto it = obs.find(x);
                int r = *next(it);
                int l = *std::prev(it);

                obs.erase(it);

                seg.update(x, 0);
                seg.update(r, r - l);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};