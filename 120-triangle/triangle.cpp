#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        
        // Use the last row as our DP array (O(n) space)
        vector<int> dp = triangle.back();   // Start with the bottom row
        
        // Start from the second last row and move upwards
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                // Update dp[col] = triangle[row][col] + min(down-left, down-right)
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }
        
        return dp[0];   // Top element now contains the minimum path sum
    }
};