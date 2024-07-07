// Problem Link: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/

#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefixX(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> prefixY(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                prefixX[i][j] = prefixX[i-1][j] + prefixX[i][j-1] - prefixX[i-1][j-1] + (grid[i-1][j-1] == 'X' ? 1 : 0);
                prefixY[i][j] = prefixY[i-1][j] + prefixY[i][j-1] - prefixY[i-1][j-1] + (grid[i-1][j-1] == 'Y' ? 1 : 0);
            }
        }

        int count = 0;

        for (int r2 = 0; r2 < n; ++r2) {
            for (int c2 = 0; c2 < m; ++c2) {
                int totalX = prefixX[r2 + 1][c2 + 1];
                int totalY = prefixY[r2 + 1][c2 + 1];
                
                if (totalX > 0 && totalX == totalY) {
                    count++;
                }
            }
        }

        return count;
    }
};
