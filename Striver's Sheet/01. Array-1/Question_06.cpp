class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], cur_max, profit = 0;

        for (int i = 1; i < prices.size(); i ++){
            cur_max = prices[i] - mini;
            profit = max(profit, cur_max);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};
