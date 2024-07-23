// Problem Link : https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution{
int helper(int i, int j, int arr[], vector<vector<int>>&dp){
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int mini = INT_MAX;
    
    for(int k=i; k<j; k++){
        mini = min(mini , helper(i, k, arr, dp) + helper(k+1,j, arr,dp) 
                        + (arr[i-1]*arr[k]*arr[j]));
    }
    return dp[i][j] = mini;
}
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return helper(1, N-1, arr, dp);
    }
};