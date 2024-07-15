// Problem Link : https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution {
private:
    int helper(int r, int c, int m, int n, vector<vector<int>>&dp, vector<vector<int>>&matrix){
        if(c<0 || c>=n) return INT_MAX;
        if(r==0) return matrix[r][c];
        if(dp[r][c] != -1) return dp[r][c];

        int mini = helper(r-1, c, n, m, dp, matrix);
        mini = min(mini, helper(r-1, c-1, m, n, dp, matrix));
        mini = min(mini, helper(r-1, c+1, m, n, dp, matrix));

        return dp[r][c] = mini + matrix[r][c];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // cols
        vector<vector<int>> dp=matrix;

        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = dp[i-1][j];
                if(j>0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                if(j<n-1) dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
                dp[i][j] += matrix[i][j];
            }
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, dp[m-1][i]);
        }
        return ans;
    }
};