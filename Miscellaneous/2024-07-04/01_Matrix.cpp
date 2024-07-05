// Probem Link: https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return mat;
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));
        
        queue<pair<pair<int,int>,int>> q; 

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            dis[r][c]=step;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol] == 0) {
                    dis[nRow][nCol] = step + 1;
                    visited[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, step + 1});
                }
            }
        }

        return dis;
    }
};