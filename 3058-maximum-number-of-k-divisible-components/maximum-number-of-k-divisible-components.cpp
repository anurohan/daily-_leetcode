class Solution {
public:
    vector<vector<int>> adj;
    int k;
    int ans = 0;

    long long dfs(int node, int parent, vector<int>& values) {
        long long sum = values[node];

        for (int nei : adj[node]) {
            if (nei == parent) continue;
            sum += dfs(nei, node, values);
        }

        if (sum % k == 0) {
            ans++;
            return 0; // cut here
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int kVal) {
        k = kVal;
        adj.resize(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, values);

        return ans;
    }
};