// Problem Link: https://www.naukri.com/code360/problems/jumping-numbers_1082148?topList=top-google-coding-interview-questions&leftPanelTab=1&leftPanelTabValue=PROBLEM

// #include <bits/stdc++.h>
using namespace std;

vector<int> findJumpingNumbers(int n) {
    vector<int> ans;

    for (int i = 0; i < 10 && i <= n; i++) {
        ans.push_back(i);
    }

    queue<int> q;
    for (int i = 1; i < 10; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        int num = q.front();
        q.pop();
        int lastDigit = num % 10;
        if (lastDigit > 0) {
            int nextNum = num * 10 + (lastDigit - 1);
            if (nextNum <= n) {
                ans.push_back(nextNum);
                q.push(nextNum);
            }
        }
        if (lastDigit < 9) {
            int nextNum = num * 10 + (lastDigit + 1);
            if (nextNum <= n) {
                ans.push_back(nextNum);
                q.push(nextNum);
            }
        }
    }
    return ans;
}

