class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(),
            [](vector<int>& a, vector<int>& b) {
                return (a[1] - a[0]) > (b[1] - b[0]);
            });

        int energy = 0;
        int ans = 0;

        for (auto &t : tasks) {

            int actual = t[0];
            int minimum = t[1];

            if (energy < minimum) {
                ans += (minimum - energy);
                energy = minimum;
            }

            energy -= actual;
        }

        return ans;
    }
};