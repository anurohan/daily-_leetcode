class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;

        long long same = 6; // ABA
        long long diff = 6; // ABC

        for (int i = 2; i <= n; i++) {
            long long newSame = (3 * same + 2 * diff) % MOD;
            long long newDiff = (2 * same + 2 * diff) % MOD;

            same = newSame;
            diff = newDiff;
        }

        return (same + diff) % MOD;
    }
};