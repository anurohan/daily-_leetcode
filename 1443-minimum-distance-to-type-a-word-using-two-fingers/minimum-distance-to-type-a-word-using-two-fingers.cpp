class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        if (n == 0) return 0;

        auto getPos = [](char c) { return c - 'A'; };
        
        auto distance = [](int a, int b) -> int {
            return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
        };

        // dp[j][k] : min cost after typing up to current char, finger1 at j, finger2 at k
        vector<vector<int>> dp(26, vector<int>(26, INT_MAX / 2));  // avoid overflow

        int first = getPos(word[0]);
        for (int j = 0; j < 26; ++j) {
            dp[first][j] = 0;   // finger 1 on first letter
            dp[j][first] = 0;   // finger 2 on first letter
        }

        for (int i = 1; i < n; ++i) {
            int prev = getPos(word[i - 1]);
            int curr = getPos(word[i]);
            int d = distance(prev, curr);

            vector<vector<int>> nextDp(26, vector<int>(26, INT_MAX / 2));

            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    if (dp[j][k] == INT_MAX / 2) continue;

                    // Option 1: Finger 1 moves from j to curr (finger 2 stays at k)
                    nextDp[curr][k] = min(nextDp[curr][k], dp[j][k] + distance(j, curr));

                    // Option 2: Finger 2 moves from k to curr (finger 1 stays at j)
                    nextDp[j][curr] = min(nextDp[j][curr], dp[j][k] + distance(k, curr));
                }
            }

            dp = std::move(nextDp);
        }

        // Find the minimum cost where at least one finger is on the last letter
        int last = getPos(word.back());
        int ans = INT_MAX;
        for (int j = 0; j < 26; ++j) {
            ans = min(ans, dp[last][j]);
            ans = min(ans, dp[j][last]);
        }
        return ans;
    }
};