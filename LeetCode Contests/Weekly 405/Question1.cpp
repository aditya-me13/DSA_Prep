// Problem Link: https://leetcode.com/problems/find-the-encrypted-string/description/

class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        
        string s1 = s.substr(0, k%n);
        string s2 = s.substr(k%n);

        string sf = s2+s1;
        return sf;
    }
};