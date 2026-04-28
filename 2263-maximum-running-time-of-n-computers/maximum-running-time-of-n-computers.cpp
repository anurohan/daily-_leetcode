class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (long long b : batteries) total += b;
        
        long long left = 0, right = total / n;
        
        while (left < right) {
            long long mid = (left + right + 1) / 2;
            
            long long power = 0;
            for (long long b : batteries) {
                power += min(b, mid);
            }
            
            if (power >= mid * n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
};