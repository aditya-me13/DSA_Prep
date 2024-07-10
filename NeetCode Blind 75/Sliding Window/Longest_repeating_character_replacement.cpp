// Problem Link : https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.size();
        int mp[26] = {0};

        int max_len = 0;
        int max_freq = 0;

        while(r<n){
            mp[s[r]-'A']++;
            if(mp[s[r]-'A'] > max_freq){
                max_freq = mp[s[r]-'A'];
            }

            if((r-l+1) - max_freq > k){
                mp[s[l]-'A']--;
                l++;
            }

            max_len = max(max_len, r-l+1);
            r++;
        }
        return max_len;
    }
};