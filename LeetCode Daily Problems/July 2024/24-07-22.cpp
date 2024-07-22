// Problem Link: https://leetcode.com/problems/sort-the-people/description/?envType=daily-question&envId=2024-07-22

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int i, j, n=names.size();
        bool swapped;
        for (i = 0; i < n - 1; i++) {
            swapped = false;
            for (j = 0; j < n - i - 1; j++) {
                if (heights[j] < heights[j + 1]) {
                    swap(heights[j], heights[j + 1]);
                    swap(names[j], names[j + 1]);
                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }
        return names;
    }
};

