class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, underscore = 0;
        
        for(char ch : moves) {
            if(ch == 'L') L++;
            else if(ch == 'R') R++;
            else underscore++;
        }
        
        return abs(R - L) + underscore;
    }
};