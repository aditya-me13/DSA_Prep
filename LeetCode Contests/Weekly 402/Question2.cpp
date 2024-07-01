// Count pairs that form a complete day II
// Problem Link: https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/description/

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<long long> remainder_count(24, 0);
        
        for(int hour : hours) {
            int remainder = hour % 24;
            remainder_count[remainder]++;
        }
        
        long long pairs = 0;
        
        for(int i = 1; i < 12; ++i) {
            pairs += remainder_count[i] * remainder_count[24 - i];
        }
        
        pairs += (remainder_count[0] * (remainder_count[0] - 1)) / 2;
        pairs += (remainder_count[12] * (remainder_count[12] - 1)) / 2;
        
        return pairs;
    }
};