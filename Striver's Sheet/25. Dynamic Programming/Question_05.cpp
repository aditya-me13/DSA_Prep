// Problem Link: https://leetcode.com/problems/edit-distance/description/

class Solution {
public:
    int helper(int i1, int i2, string &word1, string &word2, vector<vector<int>> &dp){
        if(i1 < 0) return i2 +1;
        if(i2 < 0) return i1+1;
        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(word1[i1] == word2[i2]){
            return helper(i1-1, i2-1, word1, word2, dp);
        }

        // try to delete
        int mini = helper(i1-1, i2, word1, word2, dp);
        // try to insert
        mini = min(mini, helper(i1, i2-1, word1, word2, dp));
        // try to replace
        mini = min(mini, helper(i1-1, i2-1, word1, word2, dp));

        return dp[i1][i2] = 1+mini;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, word1, word2, dp);
    }
};