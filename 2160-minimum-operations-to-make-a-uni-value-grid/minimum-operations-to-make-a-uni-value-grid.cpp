class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        
        // Flatten grid
        for (auto &row : grid) {
            for (int val : row) {
                nums.push_back(val);
            }
        }
        
        // Check feasibility
        int rem = nums[0] % x;
        for (int num : nums) {
            if (num % x != rem) return -1;
        }
        
        // Sort and find median
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        
        // Calculate operations
        int operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }
        
        return operations;
    }
};