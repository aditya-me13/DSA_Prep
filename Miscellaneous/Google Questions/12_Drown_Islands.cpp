// Problem Link : https://www.naukri.com/code360/problems/replace-o-with-x_630517?topList=top-google-coding-interview-questions&leftPanelTab=0&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
using namespace std;

void replaceOWithX(char** arr, int n, int m) {
    auto isValid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m && arr[r][c] == 'O';
    };

    vector<int> dR = {-1, 0, +1, 0};
    vector<int> dC = {0, -1, 0, +1};

    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
        if (arr[i][0] == 'O') q.push({i, 0});
        if (arr[i][m - 1] == 'O') q.push({i, m - 1});
    }

    for (int i = 0; i < m; ++i) {
        if (arr[0][i] == 'O') q.push({0, i});
        if (arr[n - 1][i] == 'O') q.push({n - 1, i});
    }

    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        int r = top.first;
        int c = top.second;
        arr[r][c] = 'D';

        for (int i = 0; i < 4; ++i) {
            int nR = r + dR[i];
            int nC = c + dC[i];
            if (isValid(nR, nC)) {
                q.push({nR, nC});
                arr[nR][nC] = 'D'; // Mark as 'D' to prevent re-visiting
            }
        }
    }

    // Final pass: convert remaining 'O's to 'X' and 'D's back to 'O'
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 'O') {
                arr[i][j] = 'X';
            } else if (arr[i][j] == 'D') {
                arr[i][j] = 'O';
            }
        }
    }
}