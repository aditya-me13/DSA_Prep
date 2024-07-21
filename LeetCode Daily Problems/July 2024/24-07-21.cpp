// Problem Link : https://leetcode.com/problems/build-a-matrix-with-conditions/description/?envType=daily-question&envId=2024-07-21

class Solution {
public:
    bool topologicalSortUtil(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, stack<int>& Stack) {
        if(!visited[v]) {
            visited[v] = true;
            recStack[v] = true;
            for (int i : adj[v]) {
                if (!visited[i] && topologicalSortUtil(i, adj, visited, recStack, Stack)) {
                    return true;
                } else if (recStack[i]) {
                    return true;
                }
            }
        }
        recStack[v] = false;
        Stack.push(v);
        return false;
    }

    vector<int> topologicalSort(vector<vector<int>>& adj, int V) {
        stack<int> Stack; 
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && topologicalSortUtil(i, adj, visited, recStack, Stack)) {
                return {};
            }
        }

        while (!Stack.empty()) {
            ans.push_back(Stack.top());
            Stack.pop();
        }

        return ans;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adjR(k);
        vector<vector<int>> adjC(k);

        for (auto const& rC : rowConditions) {
            adjR[rC[0] - 1].push_back(rC[1] - 1);
        }

        for (auto const& cC : colConditions) {
            adjC[cC[0] - 1].push_back(cC[1] - 1);
        }

        vector<int> orderR = topologicalSort(adjR, k);
        if (orderR.size() == 0) return {};

        vector<int> orderC = topologicalSort(adjC, k);
        if (orderC.size() == 0) return {};

        vector<vector<int>> mat(k, vector<int>(k, 0));

        for (int r = 0; r < k; r++) {
            int num = orderR[r];
            for (int c = 0; c < k; c++) {
                if (orderC[c] == num) {
                    mat[r][c] = num + 1;
                    break;
                }
            }
        }

        return mat;
    }
};
