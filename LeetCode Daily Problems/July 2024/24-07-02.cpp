// Problem: Intersection of two arrays ii
// Problem Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/


class Solution {
public:
    vector<int> intersect(std::vector<int>& num1, vector<int>& num2) {
        unordered_map<int, int> mp; // frequency of elements in num2
        vector<int> ans;

        // Count frequency of each element in num2
        for (auto num : num2) {
            mp[num]++;
        }

        // Check each element in num1
        for (auto num : num1) {
            // If the element is found in mp and the count is positive
            if (mp[num] > 0) {
                ans.push_back(num);
                mp[num]--;
            }
        }

        return ans;
    }
};