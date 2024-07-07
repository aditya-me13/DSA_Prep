// Problem Link: https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int drink = numBottles;
        int emptyBottles = numBottles;

        while(emptyBottles / numExchange  > 0){
            drink += emptyBottles / numExchange;
            emptyBottles -= (emptyBottles / numExchange) * (numExchange-1);
        }
        return drink;
    }
};