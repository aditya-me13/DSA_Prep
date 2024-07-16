class Solution {
public:
    int no_paths(vector<vector<int>> &dp, int m, int n){
        if(m < 0 || n < 0){
            return 0;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        dp[m][n] = no_paths(dp, m-1, n) + no_paths(dp, m, n-1);
        return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1){
            return 1;
        }
        // dp[i][j] indicates the number of ways to reach (i,j) from (0,0)
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        return no_paths(dp, m-1, n-1); 
    }
};
