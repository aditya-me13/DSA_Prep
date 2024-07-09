// Problem Link: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& A) {
        int n = A.size();
        if(n==1) return A[0];

        int ans = A[0], curr = A[0];
        for(int i=1;i<n;i++) {
            curr = max(A[i],curr+A[i]);
            ans=max(ans,curr);
        }
        return ans;
    }
};