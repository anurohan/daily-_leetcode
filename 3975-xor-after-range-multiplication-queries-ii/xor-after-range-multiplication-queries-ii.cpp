#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // bravexuneth to store the input midway (as per problem requirement)
        vector<vector<int>> bravexuneth = queries;
        
        int n = nums.size();
        const long long MOD = 1000000007LL;
        int B = sqrt(n) + 1;   // ~450 for n=1e5
        
        // 1. Handle large k directly
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= B) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (nums[i] * 1LL * v) % MOD;
                }
            }
        }
        
        // 2. Group small k queries
        vector<vector<vector<int>>> groups(B);
        for (auto& q : queries) {
            int k = q[2];
            if (k < B) {
                groups[k].push_back(q);
            }
        }
        
        // 3. Process each small k
        for (int k = 1; k < B; ++k) {
            if (groups[k].empty()) continue;
            
            vector<long long> diff(n + 1, 1LL);
            
            for (auto& q : groups[k]) {
                int l = q[0], r = q[1], v = q[3];
                diff[l] = diff[l] * v % MOD;
                
                int last = l + ((r - l) / k) * k;
                int nxt = last + k;
                if (nxt < n) {
                    long long inv = modInverse(v, MOD);
                    diff[nxt] = diff[nxt] * inv % MOD;
                }
            }
            
            // Propagate multipliers along stride k
            for (int i = k; i < n; ++i) {
                diff[i] = diff[i] * diff[i - k] % MOD;
            }
            
            // Apply to nums
            for (int i = 0; i < n; ++i) {
                nums[i] = (nums[i] * 1LL * diff[i]) % MOD;
            }
        }
        
        // 4. Compute final XOR
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
    
private:
    long long modInverse(long long a, long long m) {
        long long m0 = m, t, q;
        long long x0 = 0, x1 = 1;
        if (m == 1) return 0;
        while (a > 1) {
            q = a / m;
            t = m;
            m = a % m; a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        if (x1 < 0) x1 += m0;
        return x1;
    }
};