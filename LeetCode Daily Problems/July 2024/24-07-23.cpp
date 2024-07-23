// Problem Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23

class Solution {
public:
    vector<int> frequencySort(std::vector<int>& nums) {
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }

        sort(nums.begin(), nums.end(), [&map](int a, int b) {
            if (map[a] == map[b]) {
                return a > b; 
            }
            return map[a] < map[b];
        });
        return nums;
    }
};