class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string &word : words) {
            long long sum = 0;

            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            int rem = sum % 26;

            // 0 -> 'z', 1 -> 'y', ..., 25 -> 'a'
            ans.push_back('z' - rem);
        }

        return ans;
    }
};