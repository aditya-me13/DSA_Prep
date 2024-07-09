// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int minVal = prices[0];

        for(int i = 1; i< prices.size(); i++){
            if(prices[i] - minVal > maxProf){
                maxProf = prices[i] - minVal;
            }
            else{
                if(prices[i] < minVal) minVal = prices[i];
            }
        }

        return maxProf;
    }
};

