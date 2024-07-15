// Problem Link: https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=PROBLEM

int recursive_max(int day, int last, vector<vector<int>> &dp, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (last != i)
            {
                maxi = max(maxi, points[day][i]);
            }
        }
        return maxi;
    }

    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (last != i)
        {
            maxi = max(maxi, points[day][i] + recursive_max(day - 1, i, dp, points));
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, {-1, -1, -1, -1});
    return recursive_max(n - 1, 3, dp, points);
}