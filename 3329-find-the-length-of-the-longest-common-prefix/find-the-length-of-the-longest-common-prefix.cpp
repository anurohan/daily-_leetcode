class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;

        for (int num : arr1) {
            string s = to_string(num);
            string prefix = "";

            for (char ch : s) {
                prefix += ch;
                st.insert(prefix);
            }
        }

        int ans = 0;

        for (int num : arr2) {
            string s = to_string(num);
            string prefix = "";

            for (char ch : s) {
                prefix += ch;

                if (st.count(prefix)) {
                    ans = max(ans, (int)prefix.size());
                }
            }
        }

        return ans;
    }
};