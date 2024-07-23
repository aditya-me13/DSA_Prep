// Problem Link: https://www.naukri.com/code360/problems/1072980?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM

// #include<bits/stdc++.h>
int maxProfit(vector<int> &val, vector<int> &wt, int n, int w)
{
	vector<vector<int>> dp(n, vector<int>(w+1, 0));
	for(int i = wt[0]; i<=w; i++) dp[0][i] = val[0];

	for(int ind=1; ind<n; ind++){
		for(int W=0; W<=w; W++){
			int notTake = 0 + dp[ind-1][W];
			int take = INT_MIN;
			if(wt[ind] <= W){
				take = val[ind] + dp[ind-1][W-wt[ind]]; 
			}
			dp[ind][W] = max(take, notTake);
		}
	}
	return dp[n-1][w];
}