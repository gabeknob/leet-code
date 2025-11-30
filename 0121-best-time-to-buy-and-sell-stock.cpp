class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = INT_MAX;
        int profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            buyPrice = min(buyPrice, prices[i]);
            profit = max(profit, prices[i] - buyPrice);
        }

        return profit;
    }
};
