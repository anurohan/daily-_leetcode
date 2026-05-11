class Solution {
public:
    
    bool isValidCode(string s) {
        if (s.empty()) return false;

        for (char ch : s) {
            if (!(isalnum(ch) || ch == '_')) {
                return false;
            }
        }

        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        vector<string> electronics, grocery, pharmacy, restaurant;

        int n = code.size();

        for (int i = 0; i < n; i++) {

            if (!isActive[i]) continue;

            if (!isValidCode(code[i])) continue;

            if (businessLine[i] == "electronics") {
                electronics.push_back(code[i]);
            }
            else if (businessLine[i] == "grocery") {
                grocery.push_back(code[i]);
            }
            else if (businessLine[i] == "pharmacy") {
                pharmacy.push_back(code[i]);
            }
            else if (businessLine[i] == "restaurant") {
                restaurant.push_back(code[i]);
            }
        }

        sort(electronics.begin(), electronics.end());
        sort(grocery.begin(), grocery.end());
        sort(pharmacy.begin(), pharmacy.end());
        sort(restaurant.begin(), restaurant.end());

        vector<string> ans;

        for (string s : electronics) ans.push_back(s);
        for (string s : grocery) ans.push_back(s);
        for (string s : pharmacy) ans.push_back(s);
        for (string s : restaurant) ans.push_back(s);

        return ans;
    }
};