// Problem Link : https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2024-07-27

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = 26;
        int m = source.size();
        int k = original.size();

        vector<vector<int>> adj(n, vector<int>(n, 1e9));

        for(int i=0; i<n; i++){
            adj[i][i] = 0;
        }

        for(int i=0; i<k; i++){
            adj[original[i] - 'a'][changed[i] - 'a'] = min(adj[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i=0; i<m; i++){
            if(adj[source[i]-'a'][target[i]-'a']==1e9) return -1;
            ans += adj[source[i]-'a'][target[i]-'a'];
        }

        return ans;
    }
};