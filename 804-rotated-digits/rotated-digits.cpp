class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int x = i;
            bool valid = true, diff = false;
            
            while (x > 0) {
                int d = x % 10;
                
                if (d == 3 || d == 4 || d == 7) {
                    valid = false;
                    break;
                }
                
                if (d == 2 || d == 5 || d == 6 || d == 9) {
                    diff = true;
                }
                
                x /= 10;
            }
            
            if (valid && diff) count++;
        }
        return count;
    }
};