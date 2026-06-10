#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return 0;
        
        // Sparse Table for Range Maximum Query
        vector<vector<int>> stMax(log2(n) + 1, vector<int>(n));
        // Sparse Table for Range Minimum Query
        vector<vector<int>> stMin(log2(n) + 1, vector<int>(n));
        
        // Build sparse tables
        for (int i = 0; i < n; ++i) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                stMax[j][i] = max(stMax[j-1][i], stMax[j-1][i + (1 << (j-1))]);
                stMin[j][i] = min(stMin[j-1][i], stMin[j-1][i + (1 << (j-1))]);
            }
        }
        
        auto queryMax = [&](int L, int R) {
            int len = R - L + 1;
            int j = log2(len);
            return max(stMax[j][L], stMax[j][R - (1 << j) + 1]);
        };
        
        auto queryMin = [&](int L, int R) {
            int len = R - L + 1;
            int j = log2(len);
            return min(stMin[j][L], stMin[j][R - (1 << j) + 1]);
        };
        
        // Max-heap: {value, l, r}
        using T = tuple<long long, int, int>;
        priority_queue<T> pq;
        
        for (int l = 0; l < n; ++l) {
            long long val = (long long)queryMax(l, n-1) - queryMin(l, n-1);
            pq.emplace(val, l, n-1);
        }
        
        long long ans = 0;
        for (int cnt = 0; cnt < k && !pq.empty(); ++cnt) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            
            if (r > l) {
                long long nextVal = (long long)queryMax(l, r-1) - queryMin(l, r-1);
                pq.emplace(nextVal, l, r-1);
            }
        }
        
        return ans;
    }
};