// Problem Link : https://leetcode.com/contest/weekly-contest-407/problems/vowels-game-in-a-string/description/

class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.size();
        unordered_map<char, int> mp = {
            {'a' , 1},
            {'e' , 1},
            {'i' , 1},
            {'o' , 1},
            {'u' , 1},
        };

        int count = 0;
        for(int i=0; i<n; i++){
            if(mp.find(s[i]) != mp.end()) count++;
        }

        if (count == 0) return false;
        return true;
    }
};

