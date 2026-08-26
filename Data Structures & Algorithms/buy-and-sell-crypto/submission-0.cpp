class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int low = prices[0];

        for(int price : prices) {
            low = min (low, price);
            profit = max(profit, price - low);
        }

        return profit;
    }
};
