class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            vector<int> elems;

            int top = layer, left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            for (int j = left; j <= right; j++)
                elems.push_back(grid[top][j]);

            for (int i = top + 1; i <= bottom - 1; i++)
                elems.push_back(grid[i][right]);

            for (int j = right; j >= left; j--)
                elems.push_back(grid[bottom][j]);

            for (int i = bottom - 1; i >= top + 1; i--)
                elems.push_back(grid[i][left]);

            int len = elems.size();
            int rot = k % len;

            vector<int> rotated(len);

            for (int i = 0; i < len; i++) {
                rotated[i] = elems[(i + rot) % len];
            }

            int idx = 0;

            for (int j = left; j <= right; j++)
                grid[top][j] = rotated[idx++];

            for (int i = top + 1; i <= bottom - 1; i++)
                grid[i][right] = rotated[idx++];

            for (int j = right; j >= left; j--)
                grid[bottom][j] = rotated[idx++];

            for (int i = bottom - 1; i >= top + 1; i--)
                grid[i][left] = rotated[idx++];
        }

        return grid;
    }
};
