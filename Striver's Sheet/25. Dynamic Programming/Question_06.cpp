// Problem Link: https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
        int dp[n];
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            dp[i] = arr[i];
            for(int j=0; j<i; j++){
                if(arr[i] > arr[j]){
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
	}  
};