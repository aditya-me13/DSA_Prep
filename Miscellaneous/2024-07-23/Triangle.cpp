// Problem Link: https://leetcode.com/problems/triangle/description/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        int n = triangle.size();
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                int minimum = INT_MAX;
                if(j!=0) minimum = min(minimum, dp[i-1][j-1]);
                if(j!=i) minimum = min(minimum, dp[i-1][j]);
                dp[i][j] = minimum + triangle[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }

        return ans;
    }
};