class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        const int NEG = -1e9;
        
        vector<vector<int>> prev(n, vector<int>(k+1, NEG));
        vector<vector<int>> curr(n, vector<int>(k+1, NEG));
        
        prev[0][0] = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                fill(curr[j].begin(), curr[j].end(), NEG);
            }
            
            for(int j = 0; j < n; j++) {
                for(int c = 0; c <= k; c++) {
                    
                    int val = grid[i][j];
                    int cost = (val == 0 ? 0 : 1);
                    
                    // from top
                    if(i > 0 && prev[j][c] != NEG) {
                        if(c + cost <= k) {
                            curr[j][c + cost] = max(curr[j][c + cost],
                                                    prev[j][c] + val);
                        }
                    }
                    
                    // from left
                    if(j > 0 && curr[j-1][c] != NEG) {
                        if(c + cost <= k) {
                            curr[j][c + cost] = max(curr[j][c + cost],
                                                    curr[j-1][c] + val);
                        }
                    }
                    
                    // start cell
                    if(i == 0 && j == 0 && c == 0) {
                        curr[j][0] = 0;
                    }
                }
            }
            
            prev = curr;
        }
        
        int ans = -1;
        for(int c = 0; c <= k; c++) {
            ans = max(ans, prev[n-1][c]);
        }
        
        return ans < 0 ? -1 : ans;
    }
};
