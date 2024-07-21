// Problem Link : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/?envType=daily-question&envId=2024-07-20
// Courtesy : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/solutions/5503370/greedy-o-m-n-solution-c-python-java/?envType=daily-question&envId=2024-07-20


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0, j = 0; i < m && j < n;){
            res[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= res[i][j];
            colSum[j] -= res[i][j];
            rowSum[i] == 0 ? i++ : j++;
        }
        return res;
    }
};