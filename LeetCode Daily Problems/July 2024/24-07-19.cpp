// Problem Link:https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> list;
        
        for (int i = 0; i < matrix.size(); i++) {
            int min = INT_MAX;
            int index = 0;
            
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                    index = j;
                }
            }
             
            if (ismax(matrix, min, index)) {
                list.push_back(min);
            }
        }
        
        return list;
    }

private:
    bool ismax(vector<vector<int>>& matrix, int min, int index) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][index] > min) {
                return false;
            }
        }
        return true;
    }
};