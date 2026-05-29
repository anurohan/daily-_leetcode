class Solution {
public:
    bool canCross(int row, int col, vector<vector<int>>& cells, int day) {

        vector<vector<int>> grid(row, vector<int>(col, 0));

        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int,int>> q;

        vector<vector<int>> vis(row, vector<int>(col, 0));

        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            if (r == row - 1)
                return true;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < row &&
                    nc >= 0 && nc < col &&
                    !vis[nr][nc] &&
                    grid[nr][nc] == 0) {

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int l = 1;
        int r = cells.size();
        int ans = 0;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (canCross(row, col, cells, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }
};