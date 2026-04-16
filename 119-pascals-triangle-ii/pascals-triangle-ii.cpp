#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);  // Initialize row with all 1s
        
        // Build the row from left to right, updating in-place
        for (int i = 1; i <= rowIndex; ++i) {
            // Update from back to front to avoid using updated values prematurely
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};