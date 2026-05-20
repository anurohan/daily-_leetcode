class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int n = strs[0].size();

        vector<int> dp(n, 1);

        int longest = 1;

        for(int j = 0; j < n; j++) {

            for(int i = 0; i < j; i++) {

                bool valid = true;

                for(string &s : strs) {

                    if(s[i] > s[j]) {
                        valid = false;
                        break;
                    }
                }

                if(valid) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }

            longest = max(longest, dp[j]);
        }

        return n - longest;
    }
};