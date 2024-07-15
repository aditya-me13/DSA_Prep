# Problem Link : https://leetcode.com/problems/minimum-path-sum/description/

class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        # minimum path route from (0,0) to (i,j)
        def helper(i, j, dp, grid):
            if(i<0 or j<0):
                return float('inf')

            if(i==0 and j==0):
                return grid[i][j]

            if(dp[i][j] != -1):
                return dp[i][j]
            
            left = helper(i-1, j, dp, grid)
            right = helper(i, j-1, dp, grid)

            dp[i][j] = min(left, right) + grid[i][j]
            return dp[i][j]

        m = len(grid)
        n = len(grid[0])

        dp = [[-1 for i in range(n)] for j in range(m)]
        # return helper(m-1, n-1, dp, grid)

        for i in range(m):
            for j in range(n):
                if(i==0 and j==0):
                    dp[i][j] = grid[i][j]
                else:
                    left = float('inf')
                    right = float('inf')

                    if(i>0): left = dp[i-1][j]
                    if(j>0): right = dp[i][j-1]

                    dp[i][j] = min(left, right) + grid[i][j]

        return dp[m-1][n-1]