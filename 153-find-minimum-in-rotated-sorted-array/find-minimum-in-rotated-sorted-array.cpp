class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Minimum is in right part
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Minimum is in left part including mid
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};