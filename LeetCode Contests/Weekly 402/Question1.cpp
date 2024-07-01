// Count Pairs That Form a Complete Day I
// Problem Link: https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/description/

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        for(int i = 0; i < n; i++){
            hours[i] = hours[i] % 24;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if((hours[i] + hours[j])%24 == 0){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};