class Solution {
public:
    using ll = long long;

    struct Node {
        long long cnt;
        long long wav;
        Node(long long c = 0, long long w = 0) : cnt(c), wav(w) {}
    };

    string s;
    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node dfs(int pos, int prev2, int prev1, bool started, bool tight) {
        if (pos == (int)s.size()) {
            return Node(1, 0);
        }

        if (!tight && vis[pos][prev2][prev1][started][0])
            return dp[pos][prev2][prev1][started][0];

        int limit = tight ? (s[pos] - '0') : 9;

        long long totalCnt = 0;
        long long totalWav = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node child = dfs(pos + 1, 10, 10, false, ntight);

                totalCnt += child.cnt;
                totalWav += child.wav;
            } else {
                int nprev2 = prev1;
                int nprev1 = d;

                int extra = 0;

                if (started && prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        extra = 1;
                }

                Node child =
                    dfs(pos + 1, nprev2, nprev1, true, ntight);

                totalCnt += child.cnt;
                totalWav += child.wav + child.cnt * extra;
            }
        }

        Node res(totalCnt, totalWav);

        if (!tight) {
            vis[pos][prev2][prev1][started][0] = true;
            dp[pos][prev2][prev1][started][0] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if (n <= 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};