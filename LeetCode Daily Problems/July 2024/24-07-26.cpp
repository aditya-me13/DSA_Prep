// Problem Link : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }
        for(int i=0;i<n;i++) matrix[i][i]=0;

        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][via]!=1e9 && matrix[via][j]!=1e9)
                    {
                        matrix[i][j] = min(matrix[i][j],matrix[i][via]+matrix[via][j]);
                    }
                }
            }
        }

        int ans_city=-1;
        int max_cities=n;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<=distanceThreshold) cnt++;
            }
            if(max_cities>=cnt) 
            {
                max_cities=cnt;
                ans_city=i;
            }
        }
        return ans_city;
    }
};