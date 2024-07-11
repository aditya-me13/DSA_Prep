// Problem Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openBrackets;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                openBrackets.push(i);
            } else if (s[i] == ')') {
                int openIndex = openBrackets.top();
                openBrackets.pop();
                reverse(s.begin() + openIndex + 1, s.begin() + i);
            }
        }

        string result;
        for (char c : s) {
            if (c != '(' && c != ')') {
                result += c;
            }
        }

        return result;
    }
};

