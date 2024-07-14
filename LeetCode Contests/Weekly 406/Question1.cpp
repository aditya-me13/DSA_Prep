// Problem Link: https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/description/

class Solution {
public:
    string getSmallestString(string s) {
        for(int i=1; i<s.size(); i++){
            int num1 = s[i-1] - '0';
            int num2 = s[i] - '0';
            if((num1 & 1) == (num2 &1)){
                if(num1 > num2){swap(s[i-1], s[i]);
                return s;}
            }
        }
        return s;
    }
};