// Problem Link : https://www.naukri.com/code360/problems/total-unique-paths_1081470?leftPanelTabValue=PROBLEM

// #include <bits/stdc++.h> 

int helper(int r, int c, vector<vector<int>>&dp){
	// base cases
	if(r<0 || c<0) return 0;
	if(r==0 && c==0) return 1;

	// memoization check
	if(dp[r][c]!=-1) return dp[r][c];

	// computation
	int left = helper(r-1, c, dp);
	int right = helper(r, c-1, dp);

	// memoizaion
	return dp[r][c] = left + right;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int> (n, 0));
    // return helper(m-1, n-1, dp);
	dp[0][0] = 1;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){

		if(i==0 || j==0) dp[i][j] = 1;
		else {	
			int left = dp[i - 1][j];
			int right = dp[i][j - 1];
			dp[i][j] = left + right;
            }
        }
	}
	return dp[m-1][n-1];
}