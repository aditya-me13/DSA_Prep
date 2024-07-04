// Problem Link: https://leetcode.com/problems/generate-parentheses/description/

class Solution {
private:
    void helper(int n, int open, int close, string curr, vector<string> &a){
        if(close == n){
            a.push_back(curr);
            return;
        }
        if(open < n) helper(n, open+1, close, curr + '(', a);
        if(open > close) helper(n, open, close+1, curr + ')', a);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, 0, 0, "", ans);
        return ans;
    }
};
