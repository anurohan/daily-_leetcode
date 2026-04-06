class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obs;
        for (auto& o : obstacles) {
            obs.insert({o[0], o[1]});
        }
        int x = 0, y = 0;
        int dir = 0; // 0: North (+y), 1: East (+x), 2: South (-y), 3: West (-x)
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int maxDistSq = 0;
        
        for (int cmd : commands) {
            if (cmd == -1) {
                // Turn right
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                // Turn left
                dir = (dir + 3) % 4;
            } else {
                // Move forward cmd units (one step at a time)
                int dx = directions[dir][0];
                int dy = directions[dir][1];
                for (int step = 0; step < cmd; ++step) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (obs.count({nx, ny})) {
                        break; // Blocked by obstacle, stop this command
                    }
                    x = nx;
                    y = ny;
                    maxDistSq = max(maxDistSq, x * x + y * y);
                }
            }
        }
        return maxDistSq;
    }
};