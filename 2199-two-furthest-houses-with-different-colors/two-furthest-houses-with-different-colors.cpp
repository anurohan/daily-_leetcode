class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        
        // Check from left to right
        for(int i = 0; i < n; i++) {
            for(int j = n-1; j > i; j--) {   // start from right
                if(colors[i] != colors[j]) {
                    ans = max(ans, j - i);
                    break;                    // no need to check further for this i
                }
            }
        }
        
        return ans;
    }
};