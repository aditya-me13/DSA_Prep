// Problem Link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp; // <card, last_occurance>
        int _min = INT_MAX;
        for(int i=0; i<cards.size(); i++){
            // if card did not appear before
            if(mp.find(cards[i]) == mp.end()){
                mp[cards[i]] = i;
            }
            // card already appeared before
            else{
                int curr_min = i - mp[cards[i]] + 1;
                // update last occurance
                mp[cards[i]] = i;
                _min = min(_min, curr_min);
            }
        }
        return _min == INT_MAX ? -1 : _min;
    }
};