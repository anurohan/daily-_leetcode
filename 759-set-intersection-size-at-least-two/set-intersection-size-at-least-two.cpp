class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end ascending, if end equal then start descending
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });
        
        int ans = 0;
        int mx = -1;      // largest number chosen so far
        int secondMx = -1; // second largest number chosen so far
        
        for (auto& interval : intervals) {
            int start = interval[0];
            int end   = interval[1];
            
            // Both current points already cover this interval
            if (mx >= start && secondMx >= start) {
                continue;
            }
            
            // Only the largest point covers it → add one more (at 'end')
            if (mx >= start) {
                secondMx = mx;
                mx = end;
                ans += 1;
            } 
            // Neither covers it → add two points: (end-1, end)
            else {
                mx = end;
                secondMx = end - 1;
                ans += 2;
            }
        }
        
        return ans;
    }
};