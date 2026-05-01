class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum = 0, f = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            f += (long)i * nums[i];
        }
        
        long ans = f;
        
        for(int k = 1; k < n; k++) {
            f = f + sum - (long)n * nums[n - k];
            ans = max(ans, f);
        }
        
        return ans;
    }
};