class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);

        for (int x : nums) {
            vector<int> temp = dp;
            for (int i = 0; i < 3; i++) {
                int newSum = temp[i] + x;
                dp[newSum % 3] = max(dp[newSum % 3], newSum);
            }
        }

        return dp[0];
    }
};