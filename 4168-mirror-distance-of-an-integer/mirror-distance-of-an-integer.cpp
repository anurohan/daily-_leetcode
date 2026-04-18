class Solution {
public:
    long long mirrorDistance(int n) {
        long long original = n;
        long long reversed = 0;
        
        while (n > 0) {
            reversed = reversed * 10 + (n % 10);
            n /= 10;
        }
        
        return abs(original - reversed);
    }
};