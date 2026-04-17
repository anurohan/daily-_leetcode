#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to reverse digits (omit leading zeros)
    long long reverseNum(long long x) {
        if (x == 0) return 0;
        long long rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<long long, int> lastPos;  // reversed_value -> most recent index
        int n = nums.size();
        int minDist = n + 1;  // larger than any possible distance

        for (int i = 0; i < n; ++i) {
            long long x = nums[i];
            // Check if this number is a mirror of some previous reversed number
            if (lastPos.count(x)) {
                minDist = min(minDist, i - lastPos[x]);
            }
            // Update the position for the reverse of current number
            long long revX = reverseNum(x);
            lastPos[revX] = i;
        }

        return (minDist == n + 1) ? -1 : minDist;
    }
};