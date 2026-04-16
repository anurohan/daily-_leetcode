#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        if (n == 0) return {};
        
        vector<int> minDist(n, n);  // Initialize with a large value (n)
        unordered_map<int, int> lastSeen;
        
        // Traverse the array twice to handle circular nature
        for (int i = 0; i < 2 * n; ++i) {
            int idx = i % n;
            int num = nums[idx];
            
            if (lastSeen.count(num)) {
                int prev = lastSeen[num] % n;
                int dist = i - lastSeen[num];
                
                // Update minimum distance for both positions
                minDist[idx] = min(minDist[idx], dist);
                minDist[prev] = min(minDist[prev], dist);
            }
            
            lastSeen[num] = i;
        }
        
        // Prepare the answer for queries
        vector<int> answer;
        for (int q : queries) {
            if (minDist[q] == n) {
                answer.push_back(-1);
            } else {
                answer.push_back(minDist[q]);
            }
        }
        
        return answer;
    }
};