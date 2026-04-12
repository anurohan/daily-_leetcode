class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;  // empty t
        
        for (char c : s) {
            for (int j = n; j >= 1; --j) {  // iterate backward!
                if (c == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return dp[n];
    }
};