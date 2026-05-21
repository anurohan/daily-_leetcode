class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end());

        vector<int> startTimes;

        for (auto &e : events) {
            startTimes.push_back(e[0]);
        }

        int n = events.size();

        vector<int> suffixMax(n);

        suffixMax[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int endTime = events[i][1];
            int value = events[i][2];

            int nextIndex = upper_bound(startTimes.begin(), startTimes.end(), endTime) - startTimes.begin();

            int total = value;

            if (nextIndex < n) {
                total += suffixMax[nextIndex];
            }

            ans = max(ans, total);
        }

        return ans;
    }
};