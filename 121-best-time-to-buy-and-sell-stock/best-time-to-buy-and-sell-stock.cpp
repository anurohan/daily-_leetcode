class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;     // Track the minimum price seen so far
        int maxProfit = 0;          // Track the maximum profit
        
        for (int price : prices) {
            // Update minimum price
            if (price < minPrice) {
                minPrice = price;
            }
            // Calculate profit if sold today
            else {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }
        
        return maxProfit;
    }
};